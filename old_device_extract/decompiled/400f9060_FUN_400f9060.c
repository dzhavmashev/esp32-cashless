// Function : FUN_400f9060
// Address  : 0x400f9060
// Size     : 95 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f9060(int *param_1,uint param_2,int param_3,undefined4 param_4,int *param_5,
                undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 == (int *)0x0) {
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x22e,"!= NULL","!= NULL",param_6);
  }
  iVar2 = 0x102;
  if (((param_2 <= (uint)param_1[4]) && (iVar2 = 0x104, param_2 + param_3 <= (uint)param_1[4])) &&
     (iVar2 = 0x106, *param_1 == _DAT_3ffc56b8)) {
    uVar1 = param_2 + param_1[3] & 0xffff;
    iVar2 = (*(code *)&SUB_40081e08)(param_2 + param_1[3] & 0xffff0000,param_3 + uVar1);
    if (iVar2 == 0) {
      *param_5 = *param_5 + uVar1;
    }
  }
  memw();
  return iVar2;
}

