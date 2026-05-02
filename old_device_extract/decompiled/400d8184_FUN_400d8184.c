// Function : FUN_400d8184
// Address  : 0x400d8184
// Size     : 55 bytes


void FUN_400d8184(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_400f0780(0x3ffc5490,"g state");
  iVar1 = (*(code *)&LAB_40183e8b_1)(*(undefined4 *)(param_1 + 8));
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"l state");
    uVar2 = 5;
  }
  else {
    FUN_400f0780(0x3ffc5490,"ration)");
    uVar2 = 1;
  }
  FUN_400d7d34(param_1,uVar2);
  return;
}

