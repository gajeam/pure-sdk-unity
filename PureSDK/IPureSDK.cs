namespace PureSDK
{
    internal interface IPureSdk
    {
        void StartTracking();

        void StopTracking();

        bool IsTracking();
    }
}