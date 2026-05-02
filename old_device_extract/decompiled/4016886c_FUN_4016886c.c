// Function : FUN_4016886c
// Address  : 0x4016886c
// Size     : 86 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016886c(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  _DAT_3ff01030 = *param_1;
  memw();
  _DAT_3ff01034 = param_1[1];
  memw();
  _DAT_3ff01038 = param_1[2];
  memw();
  _DAT_3ff0103c = param_1[3];
  memw();
  memw();
  _DAT_3ff01000 = 1;
  do {
    memw();
    iVar1 = (*(code *)&SUB_40084594)(0x3ff01004);
  } while (iVar1 != 1);
  (*(code *)&SUB_400845b8)(param_2,&DAT_3ff01030,4);
  return;
}

