#pragma once

#include "AP_FW_Controller.h"

class AP_PitchController : public AP_FW_Controller
{
public:
    AP_PitchController(const AP_FixedWing &parms);

    /* Do not allow copies */
    CLASS_NO_COPY(AP_PitchController);

    float get_servo_out(int32_t angle_err, float scaler, bool disable_integrator, bool ground_mode) override;

    void set_pitch_rate_override(float desired_rate_dps)
    {
        _pitch_rate_override_active = true;
        _pitch_rate_override_dps = desired_rate_dps;
    }

    void clear_pitch_rate_override()
    {
        _pitch_rate_override_active = false;
    }

    static const struct AP_Param::GroupInfo var_info[];

    void convert_pid();

private:
    AP_Float _roll_ff;
    bool _pitch_rate_override_active = false;
    float _pitch_rate_override_dps = 0.0f;

    float _get_coordination_rate_offset(const float &aspeed, bool &inverted) const;

    float get_airspeed() const override;
    bool is_underspeed(const float aspeed) const override;
    float get_measured_rate() const override;

};
