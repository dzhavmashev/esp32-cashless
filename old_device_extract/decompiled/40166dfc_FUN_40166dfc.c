// Function : FUN_40166dfc
// Address  : 0x40166dfc
// Size     : 186 bytes


undefined4 FUN_40166dfc(uint param_1,uint param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined1 auStack_30 [48];
  
  uVar3 = param_1 & 0xff;
  uVar1 = 0xffffffff;
  if (1 < uVar3) goto LAB_40166eb5;
  puVar4 = (uint *)((uVar3 + 0xffdcc36) * 4);
  if (param_2 < 2) {
    memw();
    uVar2 = *puVar4 & 0xfffffeef;
  }
  else {
    memw();
    uVar2 = *puVar4 | 0x110;
  }
  param_1 = param_1 & 0xff;
  memw();
  *puVar4 = uVar2;
  if (param_3 == 0) {
    puVar4 = (uint *)(param_1 * 8 + 0x3ff73024);
    memw();
    uVar3 = *puVar4 & 0xfffeffff;
    memw();
LAB_40166e64:
    memw();
    *puVar4 = uVar3;
    memw();
  }
  else {
    if (param_3 == 1) {
      puVar4 = (uint *)(param_1 * 8 + 0x3ff73024);
      memw();
      uVar3 = *puVar4 | 0x10000;
      goto LAB_40166e64;
    }
    (*(code *)&SUB_4008b3d0)(auStack_30,"SucData",6);
    FUN_40166d6c(uVar3,auStack_30);
  }
  puVar4 = (uint *)(param_1 * 8 + 0x3ff73064);
  memw();
  if (param_4 == 0) {
    memw();
    *puVar4 = *puVar4 & 0xfffeffff;
    memw();
    return 0;
  }
  memw();
  *puVar4 = *puVar4 | 0x10000;
  uVar1 = 0;
LAB_40166eb5:
  memw();
  return uVar1;
}

