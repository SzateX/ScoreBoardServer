#ifndef TEAM_H
#define TEAM_H

#include <QString>
#include <QMap>
#include <memory>
#include <map>
#include "Models/Abstracts/ateam.h"

class Counter;
class ACounter;

/*!
 * \brief The Team class. Implements ATeam interface
 */
class Team : public ATeam
{
    /*!
     * \brief name contains name of team
     */
    QString name;
    /*!
     * \brief counters dictonary which contains score counters
     */
    std::map<QString, std::unique_ptr<Counter>> counters;
    /*!
     * \brief timeoutFlag flag which value is true when coach timeout
     */
    bool timeoutFlag;
    /*!
     * \brief penaltyFlag flag which value when some player is out of the play area because have penalty.
     */
    bool penaltyFlag;
public:
    /*!
     * \brief Team constructor
     * \param teamName name of team. Default "noName"
     */
    Team(QString teamName = "noName");

    // ATeam interface
public:
    /*!
     * \brief SetName method sets name of team
     * \param name the name od team which setted
     */
    void SetName(const QString &name) override;
    /*!
     * \brief GetName method
     * \return name of team in string
     */
    QString GetName() override;
    /*!
     * \brief GetCounter method returns counter from counters dictionary
     * \param key string which is key of dictionary. "primary", "secondary", "tertiary" permitted.
     * \return Reference to ACounter
     * \throws CounterKeyError when key is not permitted value
     */
    ACounter &GetCounter(const QString &key) override;
    /*!
     * \brief SetPenaltyFlag method sets player penalty flag
     * \param flag value of penalty flag
     */
    void SetPenaltyFlag(bool flag) override;
    /*!
     * \brief SwitchPenaltyFlag method switches penalty flag to opposite value
     */
    void SwitchPenaltyFlag() override;
    /*!
     * \brief GetPenaltyFlag method
     * \return penalty flag value
     */
    bool GetPenaltyFlag() override;
    /*!
     * \brief SetTimeoutFlag method sets timeout flag
     * \param flag value of timeout flag
     */
    void SetTimeoutFlag(bool flag) override;
    /*!
     * \brief SwitchTimeoutFlag method change flag to opposite value
     */
    void SwitchTimeoutFlag() override;
    /*!
     * \brief GetTimeoutFlag method
     * \return timeout flag value
     */
    bool GetTimeoutFlag() override;
};

#endif // TEAM_H
