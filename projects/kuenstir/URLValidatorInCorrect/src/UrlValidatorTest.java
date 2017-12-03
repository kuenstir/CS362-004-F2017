/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   int num = 1;
   public void testManualTest()
   {
	   UrlValidator urlVal1 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal1.isValid("http://www.google.com"));
	   System.out.println("expected: true\n");
	   
	   //scheme
	   UrlValidator urlVal2 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal2.isValid("h66p://www.google.com"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal3 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal3.isValid("https://www.google.com"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal4 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal4.isValid("://www.google.com"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal5 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal5.isValid("http//www.google.com"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal6 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal6.isValid("www.google.com"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal7 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal7.isValid("ftp://www.google.com"));
	   System.out.println("expected: true\n");
	   
	   //authority
	   UrlValidator urlVal8 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal8.isValid("http://www.google.uk"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal9 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal9.isValid("http://www.google"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal10 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal10.isValid("http://www.%%google$$.com"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal11 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal11.isValid("http://wonderful.com"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal12 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal12.isValid("http://www.some.website.com"));
	   System.out.println("expected: true\n");
	   
	   //port
	   UrlValidator urlVal13 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal13.isValid("http://www.google.com:22"));
	   System.out.println("expected: true\n");
	   
	   
	   UrlValidator urlVal14 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal14.isValid("http://www.google.com:3000"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal15 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal15.isValid("http://www.google.com!"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal16 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal16.isValid("http://www.google.com:-900"));
	   System.out.println("expected: false\n");
	   
	   UrlValidator urlVal17 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal17.isValid("http://www.google.com:700%"));
	   System.out.println("expected: false\n");
	   
	 //path
	   UrlValidator urlVal18 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal18.isValid("http://www.google.com/img/file.png"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVal19 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVal19.isValid("http://www.google.com//:-)/file.png"));
	   System.out.println("expected: false\n");
	   
	   
   }
  
   //null and integer inputs
   public void testYourFirstPartition()
   {
	   String[] inputArray = new String[300];
	   inputArray[0] = "12345";
	   inputArray[1] = null;
	   inputArray[2] = "http";
	   inputArray[3] = "google.com";
	   inputArray[4] = "@&##$";
	   inputArray[5] = "multiple.dotted.in";
	   inputArray[6] = "/path/thing.png";
	   inputArray[7] = "verylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinputverylargeinput";

	   //test scheme
	   System.out.println("\nSCHEME TEST:\n");
	   UrlValidator urlVal13 = new UrlValidator(null, null, 0);
	   num++;
	   
	   for(int i = 0; i <= 7; i++) {
		   System.out.println(urlVal13.isValidScheme(inputArray[i]));
		   System.out.println(i + 1);
		   if(i == 2) {
			   System.out.println("expected: true\n");
		   }
		   else {
			   System.out.println("expected: false\n");
		   }
	   }
	   
	   //test authority
	   System.out.println("\nAUTHORITY TEST:\n");
	   UrlValidator urlVal14 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   
	   for(int i = 0; i <= 7; i++) {
		   System.out.println(urlVal14.isValidAuthority(inputArray[i]));
		   System.out.println(i + 1);
		   if(i == 3 || i == 5) {
			   System.out.println("expected: true\n");
		   }
		   else {
			   System.out.println("expected: false\n");
		   }
	   }
	   
	   //test path
	   System.out.println("\nPATH TEST:\n");
	   UrlValidator urlVal15 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   
	   for(int i = 0; i <= 7; i++) {
		   System.out.println(urlVal15.isValidPath(inputArray[i]));
		   System.out.println(i + 1);
		   if(i == 6 || i == 1) {
			   System.out.println("expected: true\n");
		   }
		   else {
			   System.out.println("expected: false\n");
		   }
	   }
	   
	   //test query
	   System.out.println("\nQUERY TEST:\n");
	   UrlValidator urlVal16 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   
	   for(int i = 0; i <= 6; i++) {
		   System.out.println(urlVal16.isValidQuery(inputArray[i]));
		   System.out.println(i + 1);
		   if(i == 1) {
			   System.out.println("expected: true\n");
		   }
		   else {
			   System.out.println("expected: false\n");
		   }
	   }
	   
	   
	   //test fragment
	   System.out.println("\nFRAGMENT TEST:\n");
	   UrlValidator urlVal17 = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   
	   for(int i = 0; i <= 6; i++) {
		   System.out.println(urlVal17.isValidFragment(inputArray[i]));
		   System.out.println(i + 1);
		   System.out.println("expected: true\n");

	   }
	   
   }
   
   public void testYourSecondPartition(){
	   //SPECIFIC PORT NUMBER TESTS
	   
	   System.out.println("\nPORT NUMBER TESTS\n");
	   
	   UrlValidator urlVala = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVala.isValid("http://www.google.com:65535"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlValb = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlValb.isValid("http://www.google.com:4477"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlValc = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlValc.isValid("http://www.google.com:28883"));
	   System.out.println("expected: true\n");
	   
	   UrlValidator urlVald = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   System.out.println(num);
	   num++;
	   System.out.println(urlVald.isValid("http://www.google.com:28"));
	   System.out.println("expected: true\n");
	   
	   String[] inputArrayPort = new String[300];
	   inputArrayPort[0] = ":65535";
	   inputArrayPort[1] = ":4477";
	   inputArrayPort[2] = ":28883";
	   inputArrayPort[3] = ":28";
	  
	   //test Port Numbers
	   System.out.println("\nIsValidAuthority() TEST:\n");
	   UrlValidator urlVale = new UrlValidator(null, null, 0);
	   num++;
	   
	   for(int i = 0; i <= 3; i++) {
		   System.out.println(urlVale.isValidAuthority(inputArrayPort[i]));
		   System.out.println(i + 1);
		   System.out.println("expected: true\n");

	   }
  }
   
   public void testIsValid()
   {
	   UrlValidator val = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   for (int scheme = 0; scheme < schemeArray.length; scheme++) {
		   for (int authority = 0; authority < authorityArray.length; authority++) {
			   for (int path = 0; path < pathArray.length; path++) {
				   for (int query = 0; query < queryArray.length; query++) {
					   for (int fragment = 0; fragment < fragmentArray.length; fragment++) {
						   
						   String url = schemeArray[scheme].item + authorityArray[authority].item +
								        pathArray[path].item + queryArray[query].item + fragmentArray[fragment].item;
						   
						   boolean expected = schemeArray[scheme].valid && authorityArray[authority].valid &&
							        pathArray[path].valid && queryArray[query].valid && fragmentArray[fragment].valid;
						   
						   boolean result = val.isValid(url);
						   
						   /*
						    * The "assertEquals" statement causes the test to stop after the first failure.
						    * Instead, use the "if" statement to print all failing tests to the console.
						    */
						   
						   //if (expected != result) System.out.println(url);
						   assertEquals(url, expected, result);
					   }
				   }
			   }
		   }
		   
	   }	   
   }
   
   ResultPair[] schemeArray = {new ResultPair("http://", true),
		                  new ResultPair("", true),
		                  new ResultPair("ftp://", true),
		                  new ResultPair("://", false),
		                  new ResultPair("http", false)
   };
		   
   ResultPair[] authorityArray = {new ResultPair("www.google.com", true),
		                     new ResultPair("wikipedia.org", true),
		                     new ResultPair("google.ca", true),
		                     new ResultPair("google.com:1", true),
		                     new ResultPair("", false),
		                     new ResultPair(".", false)
   };

	ResultPair[] pathArray = {new ResultPair("/path", true),
			             new ResultPair("", true)
	};
	
	ResultPair[] queryArray = {new ResultPair("?query", true),
			              new ResultPair("", true)
			
	};
	
	ResultPair[] fragmentArray = {new ResultPair("#fragment", true),
			                 new ResultPair("", true)
			
	};
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}

