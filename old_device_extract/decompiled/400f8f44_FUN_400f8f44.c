// Function : FUN_400f8f44
// Address  : 0x400f8f44
// Size     : 90 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f8f44(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x1c8,"ead_raw","!= NULL");
  }
  uVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (uVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    iVar2 = *param_1;
    if (*(char *)((int)param_1 + 0x25) == '\0') {
      uVar1 = (*(code *)&SUB_4008261c)(iVar2,param_3,param_2 + param_1[3]);
    }
    else {
      uVar1 = 0x106;
      if (iVar2 == _DAT_3ffc56b8) {
        uVar1 = (*(code *)&SUB_40082784)(iVar2,param_2 + param_1[3],param_3);
      }
    }
  }
  return uVar1;
}

