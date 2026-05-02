// Function : FUN_400ed300
// Address  : 0x400ed300
// Size     : 20 bytes


undefined4 FUN_400ed300(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 auStack_24 [9];
  
  auStack_24[0] = param_3;
  FUN_400ed234(param_1,param_2,auStack_24,4);
  return auStack_24[0];
}

