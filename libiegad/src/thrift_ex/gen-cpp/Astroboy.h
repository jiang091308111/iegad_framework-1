/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Astroboy_H
#define Astroboy_H



// ============ ˵�� ============
//
// @�������� : 2016-02-28
// @������ : iegad
//
// ============================
// @��thrift �Զ����ɵĴ���
// ============================
//
// @�޸ļ�¼:
// =======================================
//  ����                     �޸���                                   �޸�˵��
// =======================================



#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "Astroboy_types.h"

namespace iegad {
    namespace thrift_ex {

#ifdef _WIN32
#pragma warning( push )
#pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

	class AstroboyIf {
	public:
	    virtual ~AstroboyIf() {}
	    virtual void Elefun(res_t& _return, const req_t& req_msg) = 0;
	};

	class AstroboyIfFactory {
	public:
	    typedef AstroboyIf Handler;

	    virtual ~AstroboyIfFactory() {}

	    virtual AstroboyIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
	    virtual void releaseHandler(AstroboyIf* /* handler */) = 0;
	};

	class AstroboyIfSingletonFactory : virtual public AstroboyIfFactory {
	public:
	    AstroboyIfSingletonFactory(const boost::shared_ptr<AstroboyIf>& iface) : iface_(iface) {}
	    virtual ~AstroboyIfSingletonFactory() {}

	    virtual AstroboyIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
		return iface_.get();
	    }
	    virtual void releaseHandler(AstroboyIf* /* handler */) {}

	protected:
	    boost::shared_ptr<AstroboyIf> iface_;
	};

	class AstroboyNull : virtual public AstroboyIf {
	public:
	    virtual ~AstroboyNull() {}
	    void Elefun(res_t& /* _return */, const req_t& /* req_msg */) {
		return;
	    }
	};

	typedef struct _Astroboy_Elefun_args__isset {
	    _Astroboy_Elefun_args__isset() : req_msg(false) {}
	    bool req_msg : 1;
	} _Astroboy_Elefun_args__isset;

	class Astroboy_Elefun_args {
	public:

	    Astroboy_Elefun_args(const Astroboy_Elefun_args&);
	    Astroboy_Elefun_args& operator=(const Astroboy_Elefun_args&);
	    Astroboy_Elefun_args() {
	    }

	    virtual ~Astroboy_Elefun_args() throw();
	    req_t req_msg;

	    _Astroboy_Elefun_args__isset __isset;

	    void __set_req_msg(const req_t& val);

	    bool operator == (const Astroboy_Elefun_args & rhs) const
	    {
		if (!(req_msg == rhs.req_msg))
		    return false;
		return true;
	    }
	    bool operator != (const Astroboy_Elefun_args &rhs) const {
		return !(*this == rhs);
	    }

	    bool operator < (const Astroboy_Elefun_args &) const;

	    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
	    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

	};


	class Astroboy_Elefun_pargs {
	public:


	    virtual ~Astroboy_Elefun_pargs() throw();
	    const req_t* req_msg;

	    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

	};

	typedef struct _Astroboy_Elefun_result__isset {
	    _Astroboy_Elefun_result__isset() : success(false) {}
	    bool success : 1;
	} _Astroboy_Elefun_result__isset;

	class Astroboy_Elefun_result {
	public:

	    Astroboy_Elefun_result(const Astroboy_Elefun_result&);
	    Astroboy_Elefun_result& operator=(const Astroboy_Elefun_result&);
	    Astroboy_Elefun_result() {
	    }

	    virtual ~Astroboy_Elefun_result() throw();
	    res_t success;

	    _Astroboy_Elefun_result__isset __isset;

	    void __set_success(const res_t& val);

	    bool operator == (const Astroboy_Elefun_result & rhs) const
	    {
		if (!(success == rhs.success))
		    return false;
		return true;
	    }
	    bool operator != (const Astroboy_Elefun_result &rhs) const {
		return !(*this == rhs);
	    }

	    bool operator < (const Astroboy_Elefun_result &) const;

	    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
	    uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

	};

	typedef struct _Astroboy_Elefun_presult__isset {
	    _Astroboy_Elefun_presult__isset() : success(false) {}
	    bool success : 1;
	} _Astroboy_Elefun_presult__isset;

	class Astroboy_Elefun_presult {
	public:


	    virtual ~Astroboy_Elefun_presult() throw();
	    res_t* success;

	    _Astroboy_Elefun_presult__isset __isset;

	    uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

	};

	class AstroboyClient : virtual public AstroboyIf {
	public:
	    AstroboyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
		setProtocol(prot);
	    }
	    AstroboyClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
		setProtocol(iprot, oprot);
	    }
	private:
	    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
		setProtocol(prot, prot);
	    }
	    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
		piprot_ = iprot;
		poprot_ = oprot;
		iprot_ = iprot.get();
		oprot_ = oprot.get();
	    }
	public:
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
		return piprot_;
	    }
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
		return poprot_;
	    }
	    void Elefun(res_t& _return, const req_t& req_msg);
	    void send_Elefun(const req_t& req_msg);
	    void recv_Elefun(res_t& _return);
	protected:
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
	    ::apache::thrift::protocol::TProtocol* iprot_;
	    ::apache::thrift::protocol::TProtocol* oprot_;
	};

	class AstroboyProcessor : public ::apache::thrift::TDispatchProcessor {
	protected:
	    boost::shared_ptr<AstroboyIf> iface_;
	    virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
	private:
	    typedef  void (AstroboyProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
	    typedef std::map<std::string, ProcessFunction> ProcessMap;
	    ProcessMap processMap_;
	    void process_Elefun(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
	public:
	    AstroboyProcessor(boost::shared_ptr<AstroboyIf> iface) :
		iface_(iface) {
		processMap_["Elefun"] = &AstroboyProcessor::process_Elefun;
	    }

	    virtual ~AstroboyProcessor() {}
	};

	class AstroboyProcessorFactory : public ::apache::thrift::TProcessorFactory {
	public:
	    AstroboyProcessorFactory(const ::boost::shared_ptr< AstroboyIfFactory >& handlerFactory) :
		handlerFactory_(handlerFactory) {}

	    ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

	protected:
	    ::boost::shared_ptr< AstroboyIfFactory > handlerFactory_;
	};

	class AstroboyMultiface : virtual public AstroboyIf {
	public:
	    AstroboyMultiface(std::vector<boost::shared_ptr<AstroboyIf> >& ifaces) : ifaces_(ifaces) {
	    }
	    virtual ~AstroboyMultiface() {}
	protected:
	    std::vector<boost::shared_ptr<AstroboyIf> > ifaces_;
	    AstroboyMultiface() {}
	    void add(boost::shared_ptr<AstroboyIf> iface) {
		ifaces_.push_back(iface);
	    }
	public:
	    void Elefun(res_t& _return, const req_t& req_msg) {
		size_t sz = ifaces_.size();
		size_t i = 0;
		for (; i < (sz - 1); ++i) {
		    ifaces_[i]->Elefun(_return, req_msg);
		}
		ifaces_[i]->Elefun(_return, req_msg);
		return;
	    }

	};

	// The 'concurrent' client is a thread safe client that correctly handles
	// out of order responses.  It is slower than the regular client, so should
	// only be used when you need to share a connection among multiple threads
	class AstroboyConcurrentClient : virtual public AstroboyIf {
	public:
	    AstroboyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
		setProtocol(prot);
	    }
	    AstroboyConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
		setProtocol(iprot, oprot);
	    }
	private:
	    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
		setProtocol(prot, prot);
	    }
	    void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
		piprot_ = iprot;
		poprot_ = oprot;
		iprot_ = iprot.get();
		oprot_ = oprot.get();
	    }
	public:
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
		return piprot_;
	    }
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
		return poprot_;
	    }
	    void Elefun(res_t& _return, const req_t& req_msg);
	    int32_t send_Elefun(const req_t& req_msg);
	    void recv_Elefun(res_t& _return, const int32_t seqid);
	protected:
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
	    boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
	    ::apache::thrift::protocol::TProtocol* iprot_;
	    ::apache::thrift::protocol::TProtocol* oprot_;
	    ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
	};

#ifdef _WIN32
#pragma warning( pop )
#endif

    }
} // namespace

#endif