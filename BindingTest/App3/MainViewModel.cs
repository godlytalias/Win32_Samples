using Microsoft.UI.Xaml.Media.Imaging;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace App3
{
    public class AllAppsViewModel
    {
        public ObservableCollection<AllAppsTileViewModel> AllAppsTiles { get; } = new ObservableCollection<AllAppsTileViewModel>
    {
        new AllAppsTileViewModel(new BitmapImage(new Uri("ms-appx:///Assets/StoreLogo.png"))),
        new AllAppsTileViewModel(new BitmapImage(new Uri("ms-appx:///Assets/StoreLogo.png")))
    };
    }
}
