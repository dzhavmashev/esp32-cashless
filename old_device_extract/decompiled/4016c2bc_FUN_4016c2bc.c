// Function : FUN_4016c2bc
// Address  : 0x4016c2bc
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016c2bc(undefined1 param_1,uint param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  
  iVar2 = (param_2 & 0xffff) + 1;
  (**(code **)(_DAT_3ffc7e64 + 0x144))(param_1,param_2 & 0xffff);
  iVar1 = (*(code *)&SUB_40084594)(0x3ff460dc);
  *param_3 = (iVar1 >> 6) / iVar2;
  iVar1 = (*(code *)&SUB_40084594)(0x3ff460e0);
  param_3[1] = (iVar1 >> 6) / iVar2;
  iVar1 = (*(code *)&SUB_40084594)(0x3ff460e4);
  iVar1 = (iVar1 / iVar2) * 8 - (*param_3 * *param_3 + param_3[1] * param_3[1]);
  iVar1 = (**(code **)(_DAT_3ffc7e64 + 0x174))((uint)(-1 < iVar1) * iVar1,0);
  pcVar3 = *(code **)(_DAT_3ffc7e64 + 0x148);
  param_3[2] = iVar1 + 8 >> 4;
  (*pcVar3)();
  return;
}

