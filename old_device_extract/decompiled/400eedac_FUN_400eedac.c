// Function : FUN_400eedac
// Address  : 0x400eedac
// Size     : 33 bytes


int FUN_400eedac(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x68) {
    FUN_400eecf0(param_3,param_1);
    param_3 = param_3 + 0x68;
  }
  return param_3;
}

