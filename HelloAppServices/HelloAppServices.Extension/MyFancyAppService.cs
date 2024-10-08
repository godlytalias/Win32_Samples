﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CommunityToolkit.AppServices;
using HelloAppServices.Extension;

namespace HelloAppServices.Extension
{
    public sealed partial class MyFancyAppService : AppServiceComponent, IMyFancyAppService
    {
        public MyFancyAppService(string appServiceName) : base(appServiceName)
        {
        }

        public async Task<int> SumAsync(int x, int y)
        {
            return x + y;
        }
    }
}