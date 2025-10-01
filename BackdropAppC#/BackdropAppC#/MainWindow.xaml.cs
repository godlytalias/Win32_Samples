using Microsoft.UI.Composition;
using Microsoft.UI.Composition.SystemBackdrops;
using Microsoft.UI.Xaml;
using Microsoft.UI.Xaml.Controls;
using Microsoft.UI.Xaml.Media.Animation;
using System.Runtime.InteropServices;
using WinRT;

namespace BackdropAppC_
{
    /// <summary>
    /// An empty window that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ToggleBackdrop_Click(object sender, RoutedEventArgs e)
        {

            // Get the main grid (parent of the rectangle)
            CreateAcrylicOnElement();
        }

        private DesktopAcrylicController _backdropController;
        private ICompositionSupportsSystemBackdrop _backdropTarget;

        private void InitializeAcrylicBackdrop()
        {
            if (_backdropController != null)
            {
                return;
            }

            var backdropConfig = new SystemBackdropConfiguration();
            var acrylicBackdrop = new DesktopAcrylicController();
            acrylicBackdrop.LuminosityOpacity = 0.2f;
            _backdropController = acrylicBackdrop;

            acrylicBackdrop.SetSystemBackdropConfiguration(backdropConfig);
        }

        // Usage
        public unsafe void CreateAcrylicOnElement()
        {
            InitializeAcrylicBackdrop();
            var visual = Microsoft.UI.Xaml.Hosting.ElementCompositionPreview.GetElementVisual(backdropRoot);
            var backdropLink = Microsoft.UI.Content.ExperimentalContentExternalBackdropLink.Create(visual.Compositor);
            if (backdropLink == null)
            {
                //TODO: HANDLE FALLBACK
                return;
            }

            var placementVisual = backdropLink.PlacementVisual;
            placementVisual.Size = new System.Numerics.Vector2((float)App._window.Bounds.Width, (float)App._window.Bounds.Height);
            
            // Continue with WinRT objects...
            _backdropTarget = backdropLink.As<ICompositionSupportsSystemBackdrop>();
            _backdropController.AddSystemBackdropTarget(_backdropTarget);
            Microsoft.UI.Xaml.Hosting.ElementCompositionPreview.SetElementChildVisual(backdropRoot, placementVisual);



            var compositor = visual.Compositor;

            // Create a rectangular clip geometry that matches the AnimatedRectangle
            var _clipGeometry = compositor.CreateRectangleGeometry();
            _clipGeometry.Size = new System.Numerics.Vector2((float)AnimatedRectangle.Width, (float)AnimatedRectangle.Height);
            _clipGeometry.Offset = new System.Numerics.Vector2((float)AnimatedRectangle.ActualOffset.X, (float)AnimatedRectangle.ActualOffset.Y);

            // Create a geometric clip and apply it to the placement visual
            var _placementClip = compositor.CreateGeometricClip(_clipGeometry);
            placementVisual.Clip = _placementClip;


        }
    }
}