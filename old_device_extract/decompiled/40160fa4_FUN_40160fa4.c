// Function : FUN_40160fa4
// Address  : 0x40160fa4
// Size     : 126 bytes


void FUN_40160fa4(uint param_1)

{
  int iVar1;
  uint *puVar2;
  
  FUN_4016677c(3);
  param_1 = param_1 & 0xff;
  (*(code *)&SUB_40008534)(0x10);
  FUN_40166738(param_1);
  FUN_4016677c(0);
  if ((((&DAT_3ffc7b2e)[param_1 * 0x24] != '\x01') || (param_1 != 4)) &&
     (iVar1 = FUN_4016675c(param_1), iVar1 == 0)) {
    if (*(int *)(&DAT_3ffc7b1c + param_1 * 0x24) != 0) {
      puVar2 = *(uint **)(*(int *)(&DAT_3ffc7b1c + param_1 * 0x24) + 0x2c);
      *puVar2 = *puVar2 | 0x20000;
    }
    memw();
    return;
  }
  FUN_40166714(param_1);
  (&DAT_3ffc7b2e)[param_1 * 0x24] = 6;
  memw();
  if (*(int *)(&DAT_3ffc7b1c + param_1 * 0x24) == 0) {
    memw();
    return;
  }
  FUN_40160578();
  return;
}

