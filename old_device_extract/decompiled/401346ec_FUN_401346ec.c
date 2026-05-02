// Function : FUN_401346ec
// Address  : 0x401346ec
// Size     : 42 bytes


int FUN_401346ec(int param_1,int param_2,int param_3)

{
  int iVar1;
  int aiStack_24 [9];
  
  memw();
  aiStack_24[0] = param_2;
  iVar1 = FUN_40136028(param_1,param_1 + 0xac,aiStack_24,param_3);
  if ((iVar1 == 0) && (aiStack_24[0] - param_2 != param_3)) {
    iVar1 = -0x4f80;
  }
  return iVar1;
}

