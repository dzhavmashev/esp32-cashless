// Function : FUN_400e712c
// Address  : 0x400e712c
// Size     : 50 bytes


void FUN_400e712c(undefined4 param_1)

{
  int iVar1;
  
  FUN_400f0780(0x3ffc5490,"=======");
  iVar1 = FUN_400e69a4(param_1);
  if (iVar1 == 0) {
    FUN_400f0780(0x3ffc5490,"zing...");
  }
  else {
    FUN_400f0780(0x3ffc5490,"storage");
    FUN_400e700c(param_1);
  }
  return;
}

