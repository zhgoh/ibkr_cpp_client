#include "ibkr_tool/CppClient.h"
#include <iostream>

CppClient::CppClient():
        osSignal{2000}, // 2 second timeout
        clientSocket{std::make_unique<EClientSocket>(this, &osSignal)} {
}

CppClient::~CppClient() = default;

bool CppClient::connect(const char *host, int port, int clientId) {
    if (!clientSocket->eConnect(host, port, clientId)) {
        std::cerr << "Cannot connect to " << host << ":" << port << "with clientId: " << clientId;
        return false;
    }
    eReader = std::make_unique<EReader>(clientSocket.get(), &osSignal);
    eReader->start();

    std::cout << "Connected...\n";

    return true;
}

void CppClient::disconnect() const {
    clientSocket->eDisconnect();
}

bool CppClient::isConnected() const {
    return clientSocket->isConnected();
}

void CppClient::tickPrice( TickerId tickerId, TickType field, double price, const TickAttrib& attrib) {}
void CppClient::tickSize(TickerId tickerId, TickType field, Decimal size) {}
void CppClient::tickOptionComputation( TickerId tickerId,
                                    TickType tickType,
                                    int tickAttrib,
                                    double impliedVol,
                                    double delta,
                                    double optPrice,
                                    double pvDividend, double gamma, double vega, double theta, double undPrice) {}
void CppClient::tickGeneric(TickerId tickerId, TickType tickType, double value) {}
void CppClient::tickString(TickerId tickerId, TickType tickType, const std::string& value) {}
void CppClient::tickEFP(TickerId tickerId, TickType tickType, double basisPoints, const std::string& formattedBasisPoints,
                     double totalDividends, int holdDays, const std::string& futureLastTradeDate, double dividendImpact, double dividendsToLastTradeDate) {}
void CppClient::orderStatus( OrderId orderId, const std::string& status, Decimal filled,
                          Decimal remaining, double avgFillPrice, int permId, int parentId,
                          double lastFillPrice, int clientId, const std::string& whyHeld, double mktCapPrice) {}
void CppClient::openOrder( OrderId orderId, const Contract&, const Order&, const OrderState&) {}
void CppClient::openOrderEnd() {}
void CppClient::winError( const std::string& str, int lastError) {}
void CppClient::connectionClosed() {}
void CppClient::updateAccountValue(const std::string& key, const std::string& val,
                                const std::string& currency, const std::string& accountName) {}
void CppClient::updatePortfolio( const Contract& contract, Decimal position,
                              double marketPrice, double marketValue, double averageCost,
                              double unrealizedPNL, double realizedPNL, const std::string& accountName) {}
void CppClient::updateAccountTime(const std::string& timeStamp) {}
void CppClient::accountDownloadEnd(const std::string& accountName) {}
void CppClient::nextValidId( OrderId orderId) {}
void CppClient::contractDetails( int reqId, const ContractDetails& contractDetails) {}
void CppClient::bondContractDetails( int reqId, const ContractDetails& contractDetails) {}
void CppClient::contractDetailsEnd( int reqId) {}
void CppClient::execDetails( int reqId, const Contract& contract, const Execution& execution) {}
void CppClient::execDetailsEnd( int reqId) {}
void CppClient::error(int id, int errorCode, const std::string& errorString, const std::string& advancedOrderRejectJson) {}
void CppClient::updateMktDepth(TickerId id, int position, int operation, int side,
                            double price, Decimal size) {}
void CppClient::updateMktDepthL2(TickerId id, int position, const std::string& marketMaker, int operation,
                              int side, double price, Decimal size, bool isSmartDepth) {}
void CppClient::updateNewsBulletin(int msgId, int msgType, const std::string& newsMessage, const std::string& originExch) {}
void CppClient::managedAccounts( const std::string& accountsList) {}
void CppClient::receiveFA(faDataType pFaDataType, const std::string& cxml) {}
void CppClient::historicalData(TickerId reqId, const Bar& bar) {}
void CppClient::historicalDataEnd(int reqId, const std::string& startDateStr, const std::string& endDateStr) {}
void CppClient::scannerParameters(const std::string& xml) {}
void CppClient::scannerData(int reqId, int rank, const ContractDetails& contractDetails,
                         const std::string& distance, const std::string& benchmark, const std::string& projection,
                         const std::string& legsStr) {}
void CppClient::scannerDataEnd(int reqId) {}
void CppClient::realtimeBar(TickerId reqId, long time, double open, double high, double low, double close,
                         Decimal volume, Decimal wap, int count) {}
void CppClient::currentTime(long time) {}
void CppClient::fundamentalData(TickerId reqId, const std::string& data) {}
void CppClient::deltaNeutralValidation(int reqId, const DeltaNeutralContract& deltaNeutralContract) {}
void CppClient::tickSnapshotEnd( int reqId) {}
void CppClient::marketDataType( TickerId reqId, int marketDataType) {}
void CppClient::commissionReport( const CommissionReport& commissionReport) {}
void CppClient::position( const std::string& account, const Contract& contract, Decimal position, double avgCost) {}
void CppClient::positionEnd() {}
void CppClient::accountSummary( int reqId, const std::string& account, const std::string& tag, const std::string& value, const std::string& curency) {}
void CppClient::accountSummaryEnd(int reqId) {}
void CppClient::verifyMessageAPI(const std::string& apiData) {}
void CppClient::verifyCompleted( bool isSuccessful, const std::string& errorText) {}
void CppClient::displayGroupList( int reqId, const std::string& groups) {}
void CppClient::displayGroupUpdated( int reqId, const std::string& contractInfo) {}
void CppClient::verifyAndAuthMessageAPI( const std::string& apiData, const std::string& xyzChallange) {}
void CppClient::verifyAndAuthCompleted( bool isSuccessful, const std::string& errorText) {}
void CppClient::connectAck() {}
void CppClient::positionMulti( int reqId, const std::string& account,const std::string& modelCode, const Contract& contract, Decimal pos, double avgCost) {}
void CppClient::positionMultiEnd( int reqId) {}
void CppClient::accountUpdateMulti( int reqId, const std::string& account, const std::string& modelCode, const std::string& key, const std::string& value, const std::string& currency) {}
void CppClient::accountUpdateMultiEnd( int reqId) {}
void CppClient::securityDefinitionOptionalParameter(int reqId, const std::string& exchange, int underlyingConId, const std::string& tradingClass,
                                                 const std::string& multiplier, const std::set<std::string>& expirations, const std::set<double>& strikes) {}
void CppClient::securityDefinitionOptionalParameterEnd(int reqId) {}
void CppClient::softDollarTiers(int reqId, const std::vector<SoftDollarTier> &tiers) {}
void CppClient::familyCodes(const std::vector<FamilyCode> &familyCodes) {}
void CppClient::symbolSamples(int reqId, const std::vector<ContractDescription> &contractDescriptions) {}
void CppClient::mktDepthExchanges(const std::vector<DepthMktDataDescription> &depthMktDataDescriptions) {}
void CppClient::tickNews(int tickerId, time_t timeStamp, const std::string& providerCode, const std::string& articleId, const std::string& headline, const std::string& extraData) {}
void CppClient::smartComponents(int reqId, const SmartComponentsMap& theMap) {}
void CppClient::tickReqParams(int tickerId, double minTick, const std::string& bboExchange, int snapshotPermissions) {}
void CppClient::newsProviders(const std::vector<NewsProvider> &newsProviders) {}
void CppClient::newsArticle(int requestId, int articleType, const std::string& articleText) {}
void CppClient::historicalNews(int requestId, const std::string& time, const std::string& providerCode, const std::string& articleId, const std::string& headline) {}
void CppClient::historicalNewsEnd(int requestId, bool hasMore) {}
void CppClient::headTimestamp(int reqId, const std::string& headTimestamp) {}
void CppClient::histogramData(int reqId, const HistogramDataVector& data) {}
void CppClient::historicalDataUpdate(TickerId reqId, const Bar& bar) {}
void CppClient::rerouteMktDataReq(int reqId, int conid, const std::string& exchange) {}
void CppClient::rerouteMktDepthReq(int reqId, int conid, const std::string& exchange) {}
void CppClient::marketRule(int marketRuleId, const std::vector<PriceIncrement> &priceIncrements) {}
void CppClient::pnl(int reqId, double dailyPnL, double unrealizedPnL, double realizedPnL) {}
void CppClient::pnlSingle(int reqId, Decimal pos, double dailyPnL, double unrealizedPnL, double realizedPnL, double value) {}
void CppClient::historicalTicks(int reqId, const std::vector<HistoricalTick> &ticks, bool done) {}
void CppClient::historicalTicksBidAsk(int reqId, const std::vector<HistoricalTickBidAsk> &ticks, bool done) {}
void CppClient::historicalTicksLast(int reqId, const std::vector<HistoricalTickLast> &ticks, bool done) {}
void CppClient::tickByTickAllLast(int reqId, int tickType, time_t time, double price, Decimal size, const TickAttribLast& tickAttribLast, const std::string& exchange, const std::string& specialConditions) {}
void CppClient::tickByTickBidAsk(int reqId, time_t time, double bidPrice, double askPrice, Decimal bidSize, Decimal askSize, const TickAttribBidAsk& tickAttribBidAsk) {}
void CppClient::tickByTickMidPoint(int reqId, time_t time, double midPoint) {}
void CppClient::orderBound(long long orderId, int apiClientId, int apiOrderId) {}
void CppClient::completedOrder(const Contract& contract, const Order& order, const OrderState& orderState) {}
void CppClient::completedOrdersEnd() {}
void CppClient::replaceFAEnd(int reqId, const std::string& text) {}
void CppClient::wshMetaData(int reqId, const std::string& dataJson) {}
void CppClient::wshEventData(int reqId, const std::string& dataJson) {}
void CppClient::historicalSchedule(int reqId, const std::string& startDateTime, const std::string& endDateTime, const std::string& timeZone, const std::vector<HistoricalSession>& sessions) {}
void CppClient::userInfo(int reqId, const std::string& whiteBrandingId) {}