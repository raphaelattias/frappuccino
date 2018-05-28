
#include "supportadessin.h"
#include "oscillateur.h"
#include <iostream>
#include <fstream>

class TextViewer : public SupportADessin {

public:
    ~TextViewer();

private:

    virtual void dessineSupport(Pendule const& pendule) override;
    virtual void dessineSupport(Ressort const& ressort) override;
    virtual void dessineSupport(Systeme const& systeme) override;
};
