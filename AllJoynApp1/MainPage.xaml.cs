using org.alljoyn.example.Rover;
using System;
using System.Threading.Tasks;
using Windows.Devices.AllJoyn;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

// see https://channel9.msdn.com/Blogs/Internet-of-Things-Blog/Using-the-AllJoyn--Studio-Extension

namespace RoverAllJoyn
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        RoverConsumer makerConsumer = null;

        public MainPage()
        {
            this.InitializeComponent();

            AllJoynBusAttachment makerBusAttachment = new AllJoynBusAttachment();
            RoverWatcher makerWatcher = new RoverWatcher(makerBusAttachment);

            makerWatcher.Added += MakerWatcher_Added;
            makerWatcher.Start();
        }

        private async void MakerWatcher_Added(RoverWatcher sender, AllJoynServiceInfo args)
        {
            RoverJoinSessionResult joinSessionResult = await RoverConsumer.JoinSessionAsync(args, sender);

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
                    await makerConsumer.AutomaticAsync();
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
