// Function : FUN_400f90c0
// Address  : 0x400f90c0
// Size     : 125 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_400f90c0(int *param_1,uint param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  uint extraout_a3;
  int *piVar2;
  uint uVar3;
  int *in_t0;
  undefined4 uStack_28;
  undefined4 auStack_24 [9];
  
  piVar2 = param_1;
  uVar3 = param_2;
  if (param_1 == (int *)0x0) {
    piVar2 = in_t0;
    (*(code *)&SUB_40094c54)("i_flash/partition.c",0x19e,"n_write","!= NULL");
    uVar3 = extraout_a3;
  }
  iVar1 = 0x102;
  if ((param_2 <= (uint)param_1[4]) && (iVar1 = 0x104, param_2 + param_4 <= (uint)param_1[4])) {
    if (*(char *)((int)piVar2 + 0x25) == '\0') {
      iVar1 = (*(code *)&SUB_4008250c)(*piVar2,param_3,param_2 + piVar2[3],param_4);
    }
    else {
      iVar1 = 0x106;
      if ((*piVar2 == _DAT_3ffc56b8) &&
         (iVar1 = FUN_400f9060(piVar2,uVar3,param_4,0,&uStack_28,auStack_24), iVar1 == 0)) {
        (*(code *)&SUB_4008b3d0)(param_3,uStack_28,param_4);
        (*(code *)&SUB_40081e78)(auStack_24[0]);
      }
    }
  }
  return iVar1;
}

