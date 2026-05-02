// Function : FUN_40147270
// Address  : 0x40147270
// Size     : 55 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40147270(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = (**(code **)(_DAT_3ffc1a34 + 0xb4))(_DAT_3ffbfc28,param_1,param_2,param_3,0xffffffff);
  if (iVar1 != 0) {
    FUN_40147fe4(1,0x800,1,"fi task",param_1,iVar1);
  }
  return iVar1;
}

