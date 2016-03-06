#ifndef SEM_INC
#define SEM_INC

typedef void sem_t;
typedef sem_t mutex_t;

mutex_t *mutex_init(void);
int mutex_unlock(mutex_t *s);
int mutex_lock(mutex_t *s);
int mutex_destroy(mutex_t *s);

sem_t *sem_init(int val);
int sem_post(sem_t *s);
int sem_wait(sem_t *s);
int sem_destroy(sem_t *s);

#endif

