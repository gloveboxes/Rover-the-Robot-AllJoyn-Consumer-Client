//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#pragma once

namespace org { namespace alljoyn { namespace example { namespace Rover {

public interface class IRoverService
{
public:
    // Implement this function to handle calls to the Left method.
    Windows::Foundation::IAsyncOperation<RoverLeftResult^>^ LeftAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Right method.
    Windows::Foundation::IAsyncOperation<RoverRightResult^>^ RightAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Forward method.
    Windows::Foundation::IAsyncOperation<RoverForwardResult^>^ ForwardAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Backward method.
    Windows::Foundation::IAsyncOperation<RoverBackwardResult^>^ BackwardAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Stop method.
    Windows::Foundation::IAsyncOperation<RoverStopResult^>^ StopAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Automatic method.
    Windows::Foundation::IAsyncOperation<RoverAutomaticResult^>^ AutomaticAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

    // Implement this function to handle calls to the Manual method.
    Windows::Foundation::IAsyncOperation<RoverManualResult^>^ ManualAsync(_In_ Windows::Devices::AllJoyn::AllJoynMessageInfo^ info );

};

} } } } 