using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CommunityToolkit.AppServices;

namespace HelloAppServices.Extension
{
    [AppService("MyFancyAppService")]
    public interface IMyFancyAppService
    {
        Task<int> SumAsync(int x, int y);
    }
}
