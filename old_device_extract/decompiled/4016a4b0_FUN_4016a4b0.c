// Function : FUN_4016a4b0
// Address  : 0x4016a4b0
// Size     : 529 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016a4b0(undefined2 param_1,byte param_2)

{
  uint uVar1;
  undefined1 auStack_190 [160];
  undefined1 auStack_f0 [180];
  undefined1 auStack_3c [12];
  undefined1 auStack_30 [48];
  
  uVar1 = (uint)(byte)(0xc - param_2);
  DAT_3ffc0740 = 0x16;
  if (2 < param_2) {
    DAT_3ffc0740 = 0x1c;
  }
  memw();
  (*(code *)&SUB_4008b3d0)(auStack_30,0x3ffc32e0,0xc);
  (*(code *)&SUB_4008b3d0)(auStack_3c,0x3ffc32ec,0xc);
  DAT_3ffc074d = *(undefined1 *)(uVar1 + 0x3ffc074f);
  memw();
  if ((_DAT_3ffca4c8 & 0x200) == 0) {
    (**(code **)(_DAT_3ffc7e64 + 0xfc))(DAT_3ffca5b9,param_1,0);
    DAT_3ffca579 = FUN_40169034(auStack_190,0x1c,0x3ffc0744,auStack_3c,9,6,0);
    DAT_3ffca578 = FUN_40169034(auStack_f0,DAT_3ffc0740,0x3ffc0750,auStack_30,uVar1,0,0);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x200;
  }
  if ((_DAT_3ffca4c8 & 0x100) == 0) {
    FUN_40169c58(1,&DAT_3ffca4c8,0x3ffc0744,DAT_3ffca579 + 1,auStack_190,9);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x100;
  }
  if ((_DAT_3ffca4c8 & 0x20000) == 0) {
    FUN_40169c58(0,&DAT_3ffca4c8,0x3ffc0750,DAT_3ffca578 + 1,auStack_f0,uVar1);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x20000;
  }
  if ((_DAT_3ffca4c8 & 0x20) == 0) {
    FUN_40169a6c(1,0,0x3ffc0744,&DAT_3ffca440,&DAT_3ffca430,0x3ffca490,DAT_3ffca579 + 1,auStack_190)
    ;
    FUN_40169a6c(0,0,0x3ffc0750,0x3ffca464,&DAT_3ffca430,0x3ffca490,DAT_3ffca578 + 1,auStack_f0);
    _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x20;
  }
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c02c);
  _DAT_3ff5c02c = (DAT_3ffca578 & 0x7f) << 8 | uVar1 & 0xffff80ff;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff5c0a4);
  _DAT_3ff5c0a4 = (DAT_3ffca579 & 0x7f) << 0xf | uVar1 & 0xffc07fff;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc | 0x800;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc | 0x1000;
  memw();
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc | 0x8000000;
  memw();
  uVar1 = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  memw();
  _DAT_3ff450dc = uVar1 | 0x10000000;
  return;
}

