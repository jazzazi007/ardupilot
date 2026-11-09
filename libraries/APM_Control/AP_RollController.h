#pragma once

#include "AP_FW_Controller.h"

class AP_RollController : public AP_FW_Controller
{
public:
    AP_RollController(const AP_FixedWing &parms);

    /* Do not allow copies */
    CLASS_NO_COPY(AP_RollController);

    float get_servo_out(int32_t angle_err, float scaler, bool disable_integrator, bool ground_mode) override;

    static const struct AP_Param::GroupInfo var_info[];

    void convert_pid();

    void set_roll_rate_override(float desired_rate_dps)
    {
        _roll_rate_override_active = true;
        _roll_rate_override_dps = desired_rate_dps;
    }

    void clear_roll_rate_override()
    {
        _roll_rate_override_active = false;
    }

private:
    float get_airspeed() const override;
    bool is_underspeed(const float aspeed) const override;
    float get_measured_rate() const override;
    bool _roll_rate_override_active = false;
    float _roll_rate_override_dps = 0.0f;
};
