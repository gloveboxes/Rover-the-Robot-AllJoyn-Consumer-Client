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

using namespace concurrency;

namespace org { namespace alljoyn { namespace example { namespace Robot {

ref class RobotConsumer;

public ref class RobotLeftResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotLeftResult^ CreateSuccessResult()
    {
        auto result = ref new RobotLeftResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotLeftResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotLeftResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotRightResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotRightResult^ CreateSuccessResult()
    {
        auto result = ref new RobotRightResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotRightResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotRightResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotForwardResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotForwardResult^ CreateSuccessResult()
    {
        auto result = ref new RobotForwardResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotForwardResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotForwardResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotBackwardResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotBackwardResult^ CreateSuccessResult()
    {
        auto result = ref new RobotBackwardResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotBackwardResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotBackwardResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotStopResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotStopResult^ CreateSuccessResult()
    {
        auto result = ref new RobotStopResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotStopResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotStopResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotAutomaticResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotAutomaticResult^ CreateSuccessResult()
    {
        auto result = ref new RobotAutomaticResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotAutomaticResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotAutomaticResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotManualResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    
    static RobotManualResult^ CreateSuccessResult()
    {
        auto result = ref new RobotManualResult();
        result->Status = Windows::Devices::AllJoyn::AllJoynStatus::Ok;
        result->m_creationContext = Concurrency::task_continuation_context::use_current();
        return result;
    }
    
    static RobotManualResult^ CreateFailureResult(_In_ int32 status)
    {
        auto result = ref new RobotManualResult();
        result->Status = status;
        return result;
    }
internal:
    Concurrency::task_continuation_context m_creationContext = Concurrency::task_continuation_context::use_default();

private:
    int32 m_status;
};

public ref class RobotJoinSessionResult sealed
{
public:
    property int32 Status
    {
        int32 get() { return m_status; }
    internal:
        void set(_In_ int32 value) { m_status = value; }
    }

    property RobotConsumer^ Consumer
    {
        RobotConsumer^ get() { return m_consumer; }
    internal:
        void set(_In_ RobotConsumer^ value) { m_consumer = value; }
    };

private:
    int32 m_status;
    RobotConsumer^ m_consumer;
};

} } } } 
