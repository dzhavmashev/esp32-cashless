// Function : FUN_4012cfd8
// Address  : 0x4012cfd8
// Size     : 301 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4012cfd8(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 uStack_125;
  undefined1 auStack_124 [256];
  int iStack_24;
  
  iStack_24 = _DAT_3ffc5708;
  memw();
  *(char *)(param_1 + 1) = (char)param_2;
  memw();
  *(char *)((int)param_1 + 5) = (char)param_3;
  memw();
  if (param_2 == 0) {
    *(undefined1 *)((int)param_1 + 6) = 2;
    *(undefined1 *)((int)param_1 + 0xf) = 1;
    memw();
  }
  param_1[0x1e] = 0x4012b518;
  param_1[0x1f] = FUN_4012b520;
  *(undefined1 *)((int)param_1 + 9) = 1;
  *(undefined1 *)(param_1 + 3) = 1;
  *(undefined1 *)((int)param_1 + 0x11) = 1;
  memw();
  param_1[6] = 1000;
  *(undefined2 *)((int)param_1 + 10) = 0x101;
  param_1[7] = 60000;
  param_1[8] = 0x10;
  *(undefined1 *)(param_1 + 9) = 0;
  *(undefined1 *)((int)param_1 + 0x25) = 0;
  memw();
  memw();
  (*(code *)&SUB_4008b530)((int)param_1 + 0x26,0xff,6);
  if (param_2 == 1) {
    (*(code *)&SUB_4008b3d0)(auStack_124," secret",0x100);
    uStack_125 = 2;
    memw();
    memw();
    puVar1 = (undefined4 *)FUN_4012c844(param_1,auStack_124,0x100,&uStack_125,1);
    if (puVar1 != (undefined4 *)0x0) goto LAB_4012d0a8;
  }
  if (param_4 != 2) goto LAB_4012d0c1;
  *param_1 = 0x3030303;
  param_1[0x27] = &DAT_3f4236a0;
  param_1[0x2b] = 0x3ffbf754;
  param_1[0x10] = 0x3ffbf760;
  param_1[0xf] = 0x3ffbf760;
  param_1[0xe] = 0x3ffbf760;
  param_1[0xd] = 0x3ffbf760;
  param_1[0x2c] = 0x3ffbf748;
  while( true ) {
    puVar1 = (undefined4 *)0x0;
LAB_4012d0a8:
    param_1 = puVar1;
    param_3 = iStack_24;
    memw();
    memw();
    if (iStack_24 == _DAT_3ffc5708) break;
    memw();
    (*(code *)&SUB_40082ec4)();
LAB_4012d0c1:
    *param_1 = 0x1030303;
    if (param_3 == 1) {
      *(undefined1 *)((int)param_1 + 3) = 2;
      memw();
    }
    memw();
    uVar2 = FUN_4012d7c4();
    param_1[0x27] = &DAT_3f4236b0;
    param_1[0x10] = uVar2;
    param_1[0x2b] = 0x3ffbf76c;
    param_1[0xf] = uVar2;
    param_1[0xe] = uVar2;
    param_1[0xd] = uVar2;
    memw();
    uVar2 = FUN_401355c4();
    param_1[0x2c] = uVar2;
    param_1[0xc] = 0x400;
    memw();
  }
  return;
}

