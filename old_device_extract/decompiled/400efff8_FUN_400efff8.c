// Function : FUN_400efff8
// Address  : 0x400efff8
// Size     : 28 bytes


undefined4 FUN_400efff8(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  uVar2 = FUN_40184768(param_1);
  uVar1 = FUN_400f1fcc(uVar1,param_2,param_3,uVar2);
  return uVar1;
}

