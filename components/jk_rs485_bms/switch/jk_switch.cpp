#include "jk_switch.h"

namespace esphome {
namespace jk_rs485_bms {

//JkRS485BmsSwitch::JkRS485BmsSwitch(bool some_param) {
//  // Constructor implementation...
//}

static const char *const TAG = "jk_rs485_bms.switch";

static const uint8_t FUNCTION_WRITE = 0x00;
static const uint8_t COMMAND_WRITE_REGISTER = 0x05;


JkRS485BmsSwitch::JkRS485BmsSwitch(bool initial_state) {
  this->write_state(initial_state);
}

void JkRS485BmsSwitch::dump_config() { LOG_SWITCH("", "JkRS485BmsSwitch DUMP CONFIG", this); }

void JkRS485BmsSwitch::write_state(bool state) {
    if (this->parent_ == nullptr) {
        ESP_LOGE(TAG, "Parent is null");
        return;
    }
    std::uint64_t value_to_send = (state) ? 0x00000001 : 0x00000000;
    
    this->publish_state(state);
    if (this->register_address_==0x14){
       this->parent_->trigger_bms2sniffer_switch16_event(this->register_address_);
    } else {
       this->parent_->trigger_bms2sniffer_switch64_event(this->register_address_, value_to_send);
    }
    //this->publish_state(state);
    
}




}  // namespace jk_rs485_bms
}  // namespace esphome

