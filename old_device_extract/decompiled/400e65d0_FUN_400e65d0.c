// Function : FUN_400e65d0
// Address  : 0x400e65d0
// Size     : 70 bytes


bool FUN_400e65d0(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 == 0) {
    FUN_400f06a4(0x3ffc5490,"request",param_2);
    *(undefined4 *)(param_1 + 0xc) = param_2;
    FUN_400f1a40(*param_1,1);
    *(undefined4 *)(param_1 + 4) = 1;
    uVar1 = FUN_400f1a9c();
    *(undefined4 *)(param_1 + 8) = uVar1;
    FUN_400f0780(0x3ffc5490,"lu ms)\n");
  }
  else {
    FUN_400f0780(0x3ffc5490,"er ON)\n");
  }
  return iVar2 == 0;
}

