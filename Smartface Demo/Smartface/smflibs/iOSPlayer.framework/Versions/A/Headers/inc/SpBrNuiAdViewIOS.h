/*
 * SpBrNuiAdViewIOS.h
 *
 *  Created on: Jan 17, 2012
 *      Author: antti
 */

#ifndef SPBRNUIADVIEWIOS_H_
#define SPBRNUIADVIEWIOS_H_

#include "SpBrNuiAdView.h"

class SpBrNuiAdViewIOS: public SpBrNuiAdView {
public:
	SpBrNuiAdViewIOS(SpBrBase* base, SpContext* context);
    SpBrNuiAdViewIOS(SpBrNuiAdViewIOS* objectToCopy);
	virtual ~SpBrNuiAdViewIOS();
	void Load();
    void Invalidate(bool without = false);
    void loadAdRequest();
    void SetRootViewController(void* vc);
    
private:
    void *adReporter;
};

#endif /* SPBRNUIADVIEWIOS_H_ */
