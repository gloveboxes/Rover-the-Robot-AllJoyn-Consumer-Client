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
        AllJoynBusAttachment roverBusAttachment = new AllJoynBusAttachment();
        RoverWatcher roverWatcher;
        RoverConsumer roverConsumer = null;

        public MainPage()
        {
            this.InitializeComponent();

            roverWatcher = new RoverWatcher(roverBusAttachment);

            roverWatcher.Added += RoverWatcher_Added;
            roverWatcher.Start();
        }

        private async void RoverWatcher_Added(RoverWatcher sender, AllJoynServiceInfo args)
        {
            RoverJoinSessionResult joinSessionResult = await RoverConsumer.JoinSessionAsync(args, sender);

            if (joinSessionResult.Status == AllJoynStatus.Ok)
            {
                roverConsumer = joinSessionResult.Consumer;

                button1.IsEnabled = true;
                StopButton.IsEnabled = true;
                LeftButton.IsEnabled = true;
                RightButton.IsEnabled = true;
                Reverse.IsEnabled = true;
                Autonomous.IsEnabled = true;
            }
        }


        private async void LeftButton_Click(object sender, RoutedEventArgs e)
        {
            await roverConsumer.LeftAsync();
        }

        private async void RightButton_Click(object sender, RoutedEventArgs e)
        {
            await roverConsumer.RightAsync();
        }

        private async void FowardButton_Click(object sender, RoutedEventArgs e)
        {

            await roverConsumer.ForwardAsync();
        }

        private async void ReverseButton_Click(object sender, RoutedEventArgs e)
        {
            await roverConsumer.BackwardAsync();
        }

        private async void StopButton_Click_1(object sender, RoutedEventArgs e)
        {
            await roverConsumer.StopAsync();
        }


        private async void Autonomous_Toggled(object sender, RoutedEventArgs e)
        {
            ToggleSwitch toggleSwitch = sender as ToggleSwitch;
            if (toggleSwitch != null)
            {
                if (toggleSwitch.IsOn == true)
                {
                    await roverConsumer.AutonomousAsync();
                }
                else
                {
                    await roverConsumer.ManualAsync();
                    await Task.Delay(1000);
                    await roverConsumer.StopAsync();
                   
                }
            }
        }
    }
}
