# 总结
---
### one-hot编码时代
 

1. 简介	


	* one-hot编码

	　　在提出词向量（Distributed representation， Word embedding， word representation）之前所有的神经网络模型（或者传统的机器学习）对词数据的处理都是将词转换为one-hot编码进行处理。NLP 中最直观，也是到目前为止最常用的词表示方法是 One-hot Representation，这种方法把每个词表示为一个很长的向量。这个向量的维度是词表大小，其中绝大多数元素为 0，只有一个维度的值为 1，这个维度就代表了当前的词。  
 　  		
		  举个栗子：  
		　　“话筒”表示为 [0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 …]   
		　　“麦克”表示为 [0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 …]  
		　　每个词都是茫茫 0 海中的一个 1。 

	　　这种 One-hot Representation 如果采用稀疏方式存储，会是非常的简洁：也就是给每个词分配一个数字 ID。比如刚才的例子中，话筒记为 3，麦克记为 8（假设从 0 开始记）。如果要编程实现的话，用 Hash 表给每个词分配一个编号就可以了。这么简洁的表示方法配合上最大熵、SVM、CRF 等等算法已经很好地完成了 NLP 领域的各种主流任务。

	
	* 这种编码方式存在的问题

		　　这种表示方法也存在一个重要的问题就是**“词汇鸿沟”**现象：任意两个词之间都是孤立的（也就是无法衡量两个词之间的相似性关系，无法用定量的方法计算，因为如果把每个词看成向量的话那么任意两个词之间是，正交的也就是毫无关系的）。光从这两个向量中看不出两个词是否有关系，哪怕是话筒和麦克这样的同义词也不能幸免于难。
	

2. 奠基性（著名）论文

	* 2003JMLR--A Neural Probabilistic Language Model--作者：Yoshua Bengio


		1. 解决的问题

			本文聚焦于三个主要的问题分别是：  

			　　1.维度灾难(特别是离散变量)，在高维下，数据的稀缺性导致统计语言模型存在很多为0的条件概率

			　　2.语言模型的参数个数随着阶数呈指数增长，所以一般这个模型的阶数不会很高，这样n-gram无法建立长远的关系
				
			　　3.n-gram无法建模出多个相似词的关系

		2. 解决问题的方法

			本文为解决上述的三个问题提出了几个新概念：

			　　1.词向量：本文中的词向量是通过学习得到的，对所有的文档提取单词制作一个词汇表，每个单词有一个唯一的索引，即词汇表每行代表一个单词的embedding（词向量），每个词的索引可以看为一个单位向量（其实就是one-hot编码），通过学习得到的词向量就可以体现出相似词语之间的关系，并且one-hot向量维度大小与词典成正比，稠密向量大小是固定值（50~300），所以不会存在维度过大的问题，导致维度灾难。

			　　2.NNML：一个三层的神经网络，结合了词向量后，通过不断训练采用BP算法来对连接权和词向量举证进行更新，这是一个非常简单的浅层网络但是也可以在简单的预测问题上获得较好的结果。

			<center>![](https://img-blog.csdnimg.cn/20200519180326951.jpg?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3NvbGl0dWRlMjM=,size_16,color_FFFFFF,t_70#pic_center)</center>

		3. 奠基之处

			本文最重要的贡献就是为词向量的出现埋下了伏笔

	* 2011--Natural Language Processing (Almost) from Scratch--作者：Ronan Collobert

		1. 解决的问题

			　　本文前part-of-speech tagging, chunking, named entity recognition, semantic role labeling使用的是原来那种 man-made 的输入特征，并且需要很多的先验知识，无法自己进行特征工程。

			　　没有一个统一的模型能够解决上述提到的问题，本文尝试使用一个模型来对这些问题进行解决

		
		2. 解决的方法

			提出了一种新的模型，这种模型有两种不同的模式分别用来解决不同的问题  

			　　1.window approach：window approach是基于n-gram模型的改造，窗口大小为n，中心的那个词为中心词，上下文各(n-1)/2个词。


		 	　　2.sentence approach是利用卷积获取上下文并将其变成大小一致的中间表示（通过修改卷积核的大小和步伐实现）。

			两个模型最后都是最大化softmax输出的正确标签类别。window approach适用于POS,CHUNK,NER, sentence approach 适用于LRS。通过这两个模型学习没有标签的数据从而实现无监督的学习目标特征。

		3. 奠基之处

			使用神经网络实现NER、LSR等自然语言处理的任务

----------



###词向量时代



1. 词向量

	* 词向量来历

		　　词向量（Distributed representation， Word embedding， word representation），词向量的来历最初可以追溯到 Hinton 在 1986 年的论文《Learning distributed representations of concepts》，但是实际发展爆炸的时期是在《Efficient Estimation of Word Representations in Vector Space》和《Distributed Representations of  Words and Phrases and their Compositionality》两篇论文发表之后，两篇论文都介绍了word2Vec的方法。

		　　

	* 词向量的意义

		　　现在的深度学习所使用的词向量应该叫做Distributed representation表示的一种低维实数向量（过高的维度在深度学习之中是不利的，可能会发生维度爆炸的问题）。这种向量一般长成这个样子：[0.792, −0.177, −0.107, 0.109, −0.542, …]。维度以 50 维和 100 维比较常见。这种向量的表示不是唯一的，后文会提到目前计算出这种向量的主流方法。（个人认为）Distributed representation 最大的贡献就是让相关或者相似的词，在距离上更接近了。向量的距离可以用最传统的欧氏距离来衡量，也可以用 cos 夹角来衡量。

2. 里程碑论文

	* 2013--Efficient Estimation of Word Representations in Vector Space--Mikolov 

		1. 解决的问题

			　　Hinton等其他人提出的训练Distributed reputation的方法的复杂度仍然较高，如果在十分庞大的数据集上进行训练的话是十分耗费时间和资源的，希望能够提出一种更好的训练出词向量的方法

		2. 解决的方法

			提出了两种简单线性模型：

			　　1.CBOW：连续词袋模型这个模型与Hinton提出的NNML很像只是去掉了非线性的隐藏层（对于NNML来说非线性的隐藏层是导致模型复杂度最主要的因素），并且不同于NNML的地方还有使用了目标词语前后的词语（NNMl仅仅使用了前面n个词）。

			　　2.skip—gram:和CBOW模型很相似，但它不是根据上下文预测当前单词，而是根据同一句话中的另一个单词最大限度地分类一个单词。更准确地说，我们使用每个当前单词作为一个具有连续投影层的对数线性分类器的输入，并在当前单词前后的一定范围内预测单词。

		<center>![](https://img-blog.csdnimg.cn/20201017155432756.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L0NsZWFyU1NT,size_16,color_FFFFFF,t_70#pic_center)</center>

		3. 里程碑

			本文对词向量训练方法的改进，十分大的刺激了词向量的使用，并且推动了NLP的发展可以说是里程碑事件也不为过

	* 2013----Distributed Representations of  Words and Phrases and their Compositionality--Mikolov 

		1. 做出的改进

			1.分层softmax：在skip-gram的softmax层进行的是完全softmax而有一种Hinton等人提出的分层softmax可以很好的节约训练的时间，有效的减少时间复杂度

			2.负采样（NEG）：对分层softmax我们仍然可以替换为另一种高效的方法噪声对比估计(NCE)。它假设一个好的模型应该能够通过 Logistic 回归来区分数据和噪声。由于我们只关心高质量的向量表示所以可以对NCE进行简化为NEG。

			3.频繁词采样：为了抵消罕见词和高频词之间的不平衡，我们使用简单的二次抽样：训练集中的每个单词W<sub>i</sub>将有一定概率被丢弃

----------



### Seq2Seq时代

1. seq2seq

	* 什么是seq2seq
		
		　　seq2seq是一种自然语言的任务，中文翻译过来也就是序列到序列任务，最经典的seq2seq任务就是机器翻译任务（如机器翻译、文本摘要、会话建模、图像字幕等场景中的任务）

2. 奠基性论文

	* 2013--Generating Sequences With Recurrent Neural Networks--作者：Graves, Alex ，bengio
	
	 	1. 解决的问题
	 		
			　　原则上，足够大的RNN应该足以产生任意复杂的序列。然而，在实践中，标准RNN无法存储关于过去输入的信息很长时间。这种失忆症削弱了RNN模拟长距记忆的能力，也会损坏其稳定性，这种问题是所有条件生成模型都有的，不确定性的问题对于真实数据来说尤其严重。

		2. 解决的方法

			1.传统的解决方法：为条件模型提出的一种补救方法是将噪声注入到预测中，然后再将其送回模型，从而将模型的鲁棒性提高到惊人的投入。

			2.本文提出的创新：本文提出了一种新型的模型来解决普通的RNN不具有长距记忆能力的问题，LSTM的结构如图所示：  
<center>![](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9tbWJpei5xcGljLmNuL21tYml6X3BuZy9CblNORWFmaWNGQWIxaDZOQ28wNWF0Qlh2ZHU3UThQaWJwNDcxRHI1WVNDTW1pYmtpYTZ4cTdxS3A4T0xHUWNqZTgzeWlhc2VjUFRmSkNvb3VpYkpIR1RRQnlwZy82NDA_d3hfZm10PXBuZw?x-oss-process=image/format,png)</center>  

		3. 奠基之处

			　　由于本文提出的LSTM模型具有长效记忆的能力所以对于seq2seq问题具有相当大的帮助，对后来的encoder-decoder模型起到了极为大的影响，可以说是NLP历史上的一个大转折




	* NIPS 2014--Sequence to Sequence Learning with Neural Networks--作者：Sutskever, Ilya, Oriol Vinyals, and Quoc V. Le 

		1. 解决的问题

			1.一般的序列学习的简单策略是用RNN将输入映射为定长的向量，然后用另一个RNN将向量映射成目标序列。虽然RNN原则上可以工作，但是由于序列任务对之前的数据也有很大的依赖，过长距离的依赖使得RNN很难训练成功

			2.在自然语言处理中有很多任务都可以归约为序列到序列的任务，例如：
  
			　　1.机器翻译问题  
			　　2.语音识别  
			　　3.图片添加注释  
			　　4.问答系统  
			　　5.文本摘要  
			
			这些问题都：  1）输入和输出可能都是不同领域  2）输入和输出可能长度不一致。


		2. 解决的方法

			我们实际模型的三大创新点：

			　　1.两个LSTM：我们使用了两个不同的LSTM，一个用输入序列，一个用于输出序列。因为这样做可以增加模型参数的数量，但计算代价可忽略不计，并且很自然的可以在多语言对上训练LSTM。（算是引用）
<center>![](https://img-blog.csdnimg.cn/20190407192831885.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ppYW93b3Nob3V6aQ==,size_16,color_FFFFFF,t_70)</center>  
			　　2.深层LSTM：我们发现深层LSTM明显优于浅层LSTM，所以我么选择了四层的LSTM。

			　　3.reverse input：我们发现颠倒输入句子的单词顺序是非常有价值的。（算一个小技巧）
		
		3. 奠基之处

			提出了Seq2Seq模型也就是等价于编码和解码模型即encode-decode，对于不同的问题编码和解码可以选择不同的模型，以后大多数的任务都沿用和改进了这种方法

----------



### encode—decode模型时代	
	

1. encode-decode


	* 什么是encode-decode

		　　encode-decode其实就是编码和解码的意思，自从seq2seq的论文发表以来，就出现了encode-decode的模型结构，通过各种理论及实验证明这种结构在seq2seq的任务上具有很好的效果
		
		编码模型需要解决问题是将变长的输入编码成定长向量，可选模型包括：  
		　　1.CNN  
		　　2.RNN，包括LSTM、GRU以及其他变形单元  
		　　3.BIRNN双向RNN，被证明在多种任务中效果优于RNN  
		　　4.fasttext：将词向量进行求和  
		解码模型可以选择  
		　　1.RNN  
		　　2.AttentionModel

			

2. 里程碑论文

	* ICLR 2015--Neural Machine Translation by Jointly Learning to Align and Translate--作者：Bahdanau, Dzmitry, KyungHyun Cho, and Yoshua Bengio

		1. 解决的问题

			　　目前基于encode-decode的机器翻译在进行编码时需要将输入转换为定长的向量，这可能使神经网络难以处理长句子，尤其是那些比训练语料库中更长的句子。Cho（2014）发现，随着输入句子长度的增加，基本的encoder-decoder的性能会迅速下降。（encoder-decoder的缺点是难以处理长句子）

		2. 解决的方法

			　　为了解决这一问题，我们引入了一种对encoder-decoder模型的拓展。每当生成的模型在翻译中生成一个单词的时候，它会（软）搜索源句中最相关信息集中的位置。然后，该模型根据与源句位置相关的上下文向量和之前产生的所有目标词来预测目标词。（引入attention机制处理长句子）  
			　　这些方法与基本的encoder-decoder最大的区别是它不试图将整个输入序列编码成一个定长的向量。相反，它将输入序列编码成向量，然后当解码翻译的时候自适应地选择向量的子集。这使得神经翻译模型避免把源句的所有信息，不管它的长度，压扁成一个定长的向量。我们发现这可以让模型更好的处理长句子。（改进的模型与原来的区别）

		3. 里程碑

			　　本文的最大贡献便是引入了注意力机制，这也是一个划时代的发现，注意力机制的实现很大程度上的提高了模型处理长句子的能力

----------


### Attention时代

1. Attention

	* 什么是Attention

		Attention详细解读：[《一文读懂Attention》](https://blog.csdn.net/u012526436/article/details/86293981?ops_request_misc=&request_id=&biz_id=102&utm_term=Attention&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-5-86293981.pc_search_result_no_baidu_js)

		简而言之就是一种处理长句的手段，这种方法可以聚焦于一句中的关键词语，从而达到减少输入的效果

2. 奠基论文

	* 2015jmlr--Show, Attend and Tell: Neural Image Caption Generation with Visual Attention--作者：K Xu, J Ba, R Kiros, K Cho, A Courville

		1. 解决的问题
		
			　　本文的任务是（image caption）用自然语言描述图片或者是视频的技术，但是之前的方法是定位识别其中的物体，再生成对应的句子，这种方法只能生成较为相似的句子，效率不高。后来也有人利用深度学习例如卷积神经网络搭配RNN或者LSTM，但是效果均差不多

		2. 解决的方法

			　　本文的创新点在于引用了注意力机制，分为soft attention机制和hard attention机制，前者训练过程使用的是标准的BP算法，后者通过最大化变分下界（变分自编码器）实现。

		3. 奠基之处

			本文主要是在image caption中引入了Attention机制并且很大程度的提高了image caption任务的效果

	* 2017ML--Attention Is All You Need--作者：A Vaswani，N Shazeer，N Parmar

		1. 解决的问题

			　　以往nlp里大量使用RNN结构和encoder-decoder结构，RNN及其衍生网络的缺点就是慢，问题在于前后隐藏状态的依赖性，无法实现并行

		2. 解决的方法

			　　文章提出的”Transformer”框架完全摒弃了递归结构，依赖注意力机制，挖掘输入和输出之间的关系，这样做最大的好处是能够并行计算了，Transformer：

			Encoder  
			  Transformer模型的Encoder由6个基本层堆叠起来，每个基本层包含两个子层，第一个子层是一个注意力机制，第二个是一个全连接前向神经网络。对两个子层都引入了残差边以及layer normalization。
			
			Decoder  
			  Transformer模型的Decoder也由6个基本层堆叠起来，每个基本层除了Encoder里面的那两个以外，还增加了一层注意力机制，同样引入残差边以及layer normalization。
<center>![](https://img-blog.csdnimg.cn/20190729214916644.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L09zY2FyNjI4MDg2OA==,size_16,color_FFFFFF,t_70)</center>  
		3. 奠基之处  
		　　本文提出了Transform框架，也正式提出了注意力机制，这种完全利用注意力机制的模型，为之后的模型提供了一个非常好的模板




----------
			
			
### Bert时代

1. 预训练

	* 预训练的意义

		　　你需要搭建一个网络模型来完成一个特定的图像分类的任务。首先，你需要随机初始化参数，然后开始训练网络，不断调整直到网络的损失越来越小。在训练的过程中，一开始初始化的参数会不断变化。当你觉得结果很满意的时候，你就可以将训练模型的参数保存下来，以便训练好的模型可以在下次执行类似任务时获得较好的结果。这个过程就是 pre-training。

	* fine—tuning

		用别人的参数、修改后的网络和自己的数据进行训练，使得参数适应自己的数据，这样一个过程，通常称之为微调（fine tuning)。

	　　所以，预训练 就是指预先训练的一个模型或者指预先训练模型的过程；微调 就是指将预训练过的模型作用于自己的数据集，并使参数适应自己数据集的过程

2. 里程碑论文

	* 2018Computation and Language--BERT: Pre-training of Deep Bidirectional Transformers for Language Understanding--作者：J Devlin, MW Chang, K Lee, K Toutanova

		1. 解决的问题

			1.如果使用预训练模型处理其他任务，那人们想要的肯定不止某个词左边的信息，而是左右两边的信息。而考虑到这点的模型ELMo只是将left-to-right和right-to-left分别训练拼接起来。

			2.如果从头开始一个模型的训练需要大量的语料与时间

			3.获取比词更高级别的句子级别的语义表征较难

			4.多任务下的迁移学习现有模型难以实现

		2. 如何解决的

			1.作者用了一个加mask的双向Transformer

			<center>![](https://img-blog.csdnimg.cn/20190407194131428.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2ppYW93b3Nob3V6aQ==,size_16,color_FFFFFF,t_70)</center>

			2.采用了pre-training的方法

			3.BERT加入了Next Sentence Prediction来和Masked-LM一起做联合训练

			4.BERT设计了更通用的输入层和输出层

		3. 里程碑
			* 引入了Masked LM，使用双向LM做模型预训练。
			* 为预训练引入了新目标NSP，它可以学习句子与句子间的关系。
			* 进一步验证了更大的模型效果更好： 12 --> 24 层。　
			* 为下游任务引入了很通用的求解框架，不再为任务做模型定制。
			* 刷新了多项NLP任务的记录，引爆了NLP无监督预训练技术。
			
			  BERT是谷歌团队糅合目前已有的NLP知识集大成者，刷新11条赛道彰显了无与伦比的实力，且极容易被用于多种NLP任务。宛若一束烟花点亮在所有NLP从业者心中。更为可贵的是谷歌选择了开源这些，让所有从业者看到了在各行各业落地的更多可能性。

			如果想详细了解bert可读：[《一文读懂Bert》](https://blog.csdn.net/jiaowoshouzi/article/details/89073944?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161509877716780274145736%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=161509877716780274145736&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-89073944.pc_search_result_no_baidu_js&utm_term=BERT)

		
			
		
			



			


		

		

					
			
			

				
　　

		
