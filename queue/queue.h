/**
 ********************************************************************************
 * @file    ${file_name}
 * @author  ${user}
 * @date    ${date}
 * @brief
 ********************************************************************************
 */

#ifdef __cplusplus
extern "C" {
#endif

/************************************
 * INCLUDES
 ************************************/
#include "dsa.h"
#include "dsa_config.h"

/************************************
 * TYPEDEFS
 ************************************/
typedef struct
{
    int32_t rear;
    int32_t front;
    int32_t size;
    int32_t *data;
} queue_t;

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

/**
 * @brief allocate memory for queue data and init front/rear/size.
 *
 * @param[out] queue queue struct to config
 * @param[in] size size of queue data
 * @return
 *      - DSA_OK: memory allocated
 *      - DSA_NO_MEM: failed to allocated memory
 */
dsa_err_t queue_init(queue_t *queue, int32_t size);

/**
 * @brief append the data in queue.
 *
 * @param[in] queue initialized queue.
 * @param[in] data data which have to append
 * @return
 *      - DSA_OK: data appended successfully.
 *      - DSA_FAIL: queue is full.
 */
dsa_err_t queue_enqueue(queue_t *queue, int32_t data);

/**
 * @brief get the data from queue.
 *
 * @param[in] queue initialized queue.
 * @param[out] data queue retrived value.
 * @return
 *      - DSA_OK: data appended successfully.
 *      - DSA_FAIL: queue is empty.
 */
dsa_err_t queue_dequeue(queue_t *queue, int32_t *data);

/**
 * @brief get the front data from queue.
 *
 * @param[in] queue initialized queue.
 * @param[out] f_data queue front value.
 * @return
 *      - DSA_OK: data retrived successfully.
 *      - DSA_FAIL: queue is empty.
 */
dsa_err_t queue_get_front_data(queue_t *queue, int32_t *f_data);

/**
 * @brief get the rear data from queue.
 *
 * @param[in] queue initialized queue.
 * @param[out] r_data queue front value.
 * @return
 *      - DSA_OK: data retrived successfully.
 *      - DSA_FAIL: queue is empty.
 */
dsa_err_t queue_get_rear_data(queue_t *queue, int32_t *r_data);

/**
 * @brief check queue is full
 *
 * @param[in] queue initialized queue.
 * @return
 *      - DSA_OK: queue is full.
 *      - DSA_FAIL: queue is not full.
 */
dsa_err_t queue_is_full(queue_t *queue);

/**
 * @brief check queue is empty
 *
 * @param[in] queue initialized queue.
 * @return
 *      - DSA_OK: queue is empty.
 *      - DSA_FAIL: queue is not empty.
 */
dsa_err_t queue_is_empty(queue_t *queue);

/**
 * @brief allocate memory for queue data and init front/rear/size.
 *
 * @param[out] queue queue struct to config
 * @param[in] size size of queue data
 * @return
 *      - DSA_OK: memory allocated
 *      - DSA_NO_MEM: failed to allocated memory
 */
dsa_err_t queue_circular_init(queue_t *queue, int32_t size);

/**
 * @brief get circular queue front ptr.
 *
 * @param queue initialized queue.
 * @param rear rear value
 * @return
 *      - DSA_OK: data appended successfully.
 *      - DSA_FAIL: queue is full.
 */
dsa_err_t queue_ciruclar_rear(queue_t *queue, int32_t *rear);

/**
 * @brief get circular queue front ptr.
 *
 * @param queue initialized queue.
 * @param front front value
 * @return
 *      - DSA_OK: data appended successfully.
 *      - DSA_FAIL: queue is full.
 */
dsa_err_t queue_circular_front(queue_t *queue, int32_t *front);

/**
 * @brief append the data in queue.
 *
 * @param[in] queue initialized queue.
 * @param[in] data data which have to append
 * @return
 *      - DSA_OK: data appended successfully.
 *      - DSA_FAIL: queue is full.
 */
dsa_err_t queue_circular_enqueue(queue_t *queue, int32_t data);

/**
 * @brief get the front data from queue.
 *
 * @param[in] queue initialized queue.
 * @param[out] f_data queue front value.
 * @return
 *      - DSA_OK: data retrived successfully.
 *      - DSA_FAIL: queue is empty.
 */
dsa_err_t queue_circular_dequeue(queue_t *queue, int32_t *data);

#ifdef __cplusplus
}
#endif
