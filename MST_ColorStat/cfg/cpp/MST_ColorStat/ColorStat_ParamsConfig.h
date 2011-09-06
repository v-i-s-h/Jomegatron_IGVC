//#line 2 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
// *********************************************************
// 
// File autogenerated for the MST_ColorStat package 
// by the dynamic_reconfigure package.
// Please do not edit.
// 
// ********************************************************/

/***********************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 ***********************************************************/

// Author: Blaise Gassend


#ifndef __MST_ColorStat__COLORSTAT_PARAMSCONFIG_H__
#define __MST_ColorStat__COLORSTAT_PARAMSCONFIG_H__

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/config_init_mutex.h>

namespace MST_ColorStat
{
  class ColorStat_ParamsConfigStatics;
  
  class ColorStat_ParamsConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l, 
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }
      
      virtual void clamp(ColorStat_ParamsConfig &config, const ColorStat_ParamsConfig &max, const ColorStat_ParamsConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const ColorStat_ParamsConfig &config1, const ColorStat_ParamsConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, ColorStat_ParamsConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const ColorStat_ParamsConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ColorStat_ParamsConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const ColorStat_ParamsConfig &config) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;
    
    template <class T>
    class ParamDescription : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string name, std::string type, uint32_t level, 
          std::string description, std::string edit_method, T ColorStat_ParamsConfig::* f) :
        AbstractParamDescription(name, type, level, description, edit_method),
        field(f)
      {}

      T (ColorStat_ParamsConfig::* field);

      virtual void clamp(ColorStat_ParamsConfig &config, const ColorStat_ParamsConfig &max, const ColorStat_ParamsConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;
        
        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const ColorStat_ParamsConfig &config1, const ColorStat_ParamsConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, ColorStat_ParamsConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const ColorStat_ParamsConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ColorStat_ParamsConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const ColorStat_ParamsConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }
    };

//#line 14 "../cfg/ColorStat_Params.cfg"
      bool reset;
//#line 15 "../cfg/ColorStat_Params.cfg"
      bool enabled;
//#line 16 "../cfg/ColorStat_Params.cfg"
      int xMin;
//#line 17 "../cfg/ColorStat_Params.cfg"
      int xMax;
//#line 18 "../cfg/ColorStat_Params.cfg"
      int yMin;
//#line 19 "../cfg/ColorStat_Params.cfg"
      int yMax;
//#line 138 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        if ((*i)->fromMessage(msg, *this))
          count++;
      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("ColorStat_ParamsConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toMessage(msg, *this);
    }
    
    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      __toMessage__(msg, __param_descriptions__);
    }
    
    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->fromServer(nh, *this);
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const ColorStat_ParamsConfig &__max__ = __getMax__();
      const ColorStat_ParamsConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const ColorStat_ParamsConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        (*i)->calcLevel(level, config, *this);
      return level;
    }
    
    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const ColorStat_ParamsConfig &__getDefault__();
    static const ColorStat_ParamsConfig &__getMax__();
    static const ColorStat_ParamsConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    
  private:
    static const ColorStat_ParamsConfigStatics *__get_statics__();
  };
  
  template <> // Max and min are ignored for strings.
  inline void ColorStat_ParamsConfig::ParamDescription<std::string>::clamp(ColorStat_ParamsConfig &config, const ColorStat_ParamsConfig &max, const ColorStat_ParamsConfig &min) const
  {
    return;
  }

  class ColorStat_ParamsConfigStatics
  {
    friend class ColorStat_ParamsConfig;
    
    ColorStat_ParamsConfigStatics()
    {
//#line 14 "../cfg/ColorStat_Params.cfg"
      __min__.reset = 0;
//#line 14 "../cfg/ColorStat_Params.cfg"
      __max__.reset = 1;
//#line 14 "../cfg/ColorStat_Params.cfg"
      __default__.reset = 0;
//#line 14 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<bool>("reset", "bool", 1, "Reset statistics each frame.", "", &ColorStat_ParamsConfig::reset)));
//#line 15 "../cfg/ColorStat_Params.cfg"
      __min__.enabled = 0;
//#line 15 "../cfg/ColorStat_Params.cfg"
      __max__.enabled = 1;
//#line 15 "../cfg/ColorStat_Params.cfg"
      __default__.enabled = 0;
//#line 15 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<bool>("enabled", "bool", 1, "Statistics gathering enabled.", "", &ColorStat_ParamsConfig::enabled)));
//#line 16 "../cfg/ColorStat_Params.cfg"
      __min__.xMin = 0;
//#line 16 "../cfg/ColorStat_Params.cfg"
      __max__.xMin = 640;
//#line 16 "../cfg/ColorStat_Params.cfg"
      __default__.xMin = 270;
//#line 16 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<int>("xMin", "int", 1, "xMin of statistics gathering box.", "", &ColorStat_ParamsConfig::xMin)));
//#line 17 "../cfg/ColorStat_Params.cfg"
      __min__.xMax = 0;
//#line 17 "../cfg/ColorStat_Params.cfg"
      __max__.xMax = 640;
//#line 17 "../cfg/ColorStat_Params.cfg"
      __default__.xMax = 370;
//#line 17 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<int>("xMax", "int", 1, "xMax of statistics gathering box.", "", &ColorStat_ParamsConfig::xMax)));
//#line 18 "../cfg/ColorStat_Params.cfg"
      __min__.yMin = 0;
//#line 18 "../cfg/ColorStat_Params.cfg"
      __max__.yMin = 480;
//#line 18 "../cfg/ColorStat_Params.cfg"
      __default__.yMin = 0;
//#line 18 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<int>("yMin", "int", 1, "yMin of statistics gathering box.", "", &ColorStat_ParamsConfig::yMin)));
//#line 19 "../cfg/ColorStat_Params.cfg"
      __min__.yMax = 0;
//#line 19 "../cfg/ColorStat_Params.cfg"
      __max__.yMax = 480;
//#line 19 "../cfg/ColorStat_Params.cfg"
      __default__.yMax = 100;
//#line 19 "../cfg/ColorStat_Params.cfg"
      __param_descriptions__.push_back(ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr(new ColorStat_ParamsConfig::ParamDescription<int>("yMax", "int", 1, "yMax of statistics gathering box.", "", &ColorStat_ParamsConfig::yMax)));
//#line 239 "/opt/ros/electric/stacks/driver_common/dynamic_reconfigure/templates/ConfigType.h"
    
      for (std::vector<ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); i++)
        __description_message__.parameters.push_back(**i);
      __max__.__toMessage__(__description_message__.max, __param_descriptions__); 
      __min__.__toMessage__(__description_message__.min, __param_descriptions__); 
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__); 
    }
    std::vector<ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    ColorStat_ParamsConfig __max__;
    ColorStat_ParamsConfig __min__;
    ColorStat_ParamsConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;
    static const ColorStat_ParamsConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static ColorStat_ParamsConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &ColorStat_ParamsConfig::__getDescriptionMessage__() 
  {
    return __get_statics__()->__description_message__;
  }

  inline const ColorStat_ParamsConfig &ColorStat_ParamsConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }
  
  inline const ColorStat_ParamsConfig &ColorStat_ParamsConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }
  
  inline const ColorStat_ParamsConfig &ColorStat_ParamsConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }
  
  inline const std::vector<ColorStat_ParamsConfig::AbstractParamDescriptionConstPtr> &ColorStat_ParamsConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const ColorStat_ParamsConfigStatics *ColorStat_ParamsConfig::__get_statics__()
  {
    const static ColorStat_ParamsConfigStatics *statics;
  
    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = ColorStat_ParamsConfigStatics::get_instance();
    
    return statics;
  }


}

#endif // __COLORSTAT_PARAMSRECONFIGURATOR_H__
