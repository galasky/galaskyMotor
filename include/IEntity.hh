#ifndef	__ENTITY_HH__
#define	__ENTITY_HH__

class	IEntity
{
public:
  virtual ~IEntity() {}
  virtual void	draw() = 0;
  virtual void	left() = 0;
  virtual void	right() = 0;
  virtual void	catch_event() = 0;
};

#endif
