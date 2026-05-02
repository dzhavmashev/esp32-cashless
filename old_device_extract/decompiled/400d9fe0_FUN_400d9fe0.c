// Function : FUN_400d9fe0
// Address  : 0x400d9fe0
// Size     : 52 bytes


void FUN_400d9fe0(int param_1,int param_2)

{
  int iVar1;
  int iStack_28;
  int aiStack_24 [9];
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 != param_2) {
    *(int *)(param_1 + 0xc) = param_2;
    *(int *)(param_1 + 0x14) = param_2;
    FUN_400f06a4(0x3ffc5490,"ode %d\n",iVar1,param_2);
    if (*(int *)(param_1 + 0x54) != 0) {
      iStack_28 = iVar1;
      aiStack_24[0] = param_2;
      (**(code **)(param_1 + 0x58))(param_1 + 0x4c,&iStack_28,aiStack_24);
    }
  }
  return;
}

