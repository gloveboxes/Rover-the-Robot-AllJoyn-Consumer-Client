using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.Devices.AllJoyn;
using com.glovebox.rover.RPIROBOTAllJoyn.MainInterface;
using System.Threading.Tasks;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

// see https://channel9.msdn.com/Blogs/Internet-of-Things-Blog/Using-the-AllJoyn--Studio-Extension

namespace RoverAllJoyn
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        MainInterfaceConsumer makerConsumer = null;

        public MainPage()
        {
            this.InitializeComponent();

            AllJoynBusAttachment makerBusAttachment = new AllJoynBusAttachment();
            MainInterfaceWatcher makerWatcher = new MainInterfaceWatcher(makerBusAttachment);

            makerWatcher.Added += MakerWatcher_Added;
            makerWatcher.Start();
        }

        private async void MakerWatcher_Added(MainInterfaceWatcher sender, AllJoynServiceInfo args)
        {
            MainInterfaceJoinSessionResult joinSessionResult = await MainInterfaceConsumer.JoinSessionAsync(args, sender);

            if (joinSessionResult.Status == AllJoynStatus.Ok)
            {
                makerConsumer = joinSessionResult.Consumer;

                button1.IsEnabled = true;
                StopButton.IsEnabled = true;
                LeftButton.IsEnabled = true;
                RightButton.IsEnabled = true;
                Autonomous.IsEnabled = true;
            }
        }


        private async void LeftButton_Click(object sender, RoutedEventArgs e)
        {
            await makerConsumer.LeftAsync();
        }

        private async void RightButton_Click(object sender, RoutedEventArgs e)
        {
            await makerConsumer.RightAsync();
        }

        private async void FowardButton_Click(object sender, RoutedEventArgs e)
        {

            await makerConsumer.ForwardAsync();
        }

        private async void StopButton_Click_1(object sender, RoutedEventArgs e)
        {
            await makerConsumer.StopAsync();
        }


        private async void Autonomous_Toggled(object sender, RoutedEventArgs e)
        {
            ToggleSwitch toggleSwitch = sender as ToggleSwitch;
            if (toggleSwitch != null)
            {
                if (toggleSwitch.IsOn == true)
                {
                    await makerConsumer.AutonomousAsync();
                }
                else
                {
                    await makerConsumer.ManualAsync();
                    await Task.Delay(1000);
                    await makerConsumer.StopAsync();
                   
                }
            }
        }
    }
}
