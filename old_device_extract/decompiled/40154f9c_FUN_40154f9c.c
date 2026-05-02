// Function : FUN_40154f9c
// Address  : 0x40154f9c
// Size     : 97 bytes


undefined1 * FUN_40154f9c(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  puVar1 = (undefined1 *)FUN_40154dd4();
  iVar2 = (*(code *)&SUB_4008b33c)(puVar1,"       ",2);
  if (iVar2 != 0) {
    *param_1 = 7;
    param_1[1] = 6;
    memw();
    param_1[2] = *puVar1;
    memw();
    param_1[3] = puVar1[1];
    memw();
    param_1[4] = puVar1[2];
    memw();
    param_1[5] = puVar1[3];
    memw();
    param_1[6] = puVar1[4];
    memw();
    param_1[7] = puVar1[5];
    memw();
    param_1 = param_1 + 8;
  }
  memw();
  return param_1;
}

