//
// Created by ss on 19-1-13.
//

#ifndef THUNDERGBM_METRIC_H
#define THUNDERGBM_METRIC_H

#include <thundergbm/syncarray.h>
#include <thundergbm/dataset.h>
#include "thundergbm/thundergbm.h"

class Metric {
public:
    virtual float_type get_score(const SyncArray<float_type> &y_p) const = 0;

    virtual void configure(const GBMParam &param, const DataSet &dataset) {
        y.resize(dataset.y.size());
        y.copy_from(dataset.y.data(), dataset.n_instances());
    };

    static Metric *create(string name);

    virtual string get_name() const = 0;
protected:
    SyncArray<float_type> y;
};


#endif //THUNDERGBM_METRIC_H
