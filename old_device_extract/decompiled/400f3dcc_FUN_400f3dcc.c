// Function : FUN_400f3dcc
// Address  : 0x400f3dcc
// Size     : 118 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f3dcc(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 in_PRID;
  
  uVar1 = (*(code *)&SUB_4000c84c)(0xeffffff,0xff,param_1);
  if ((uVar1 & 1) == 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"encyMhz","hz",uVar2,"encyMhz","on_core",0xa6,"d): %s\n");
    uVar2 = 0x102;
  }
  else {
    (*(code *)&SUB_40092a98)(0x3ffbdc34,0xffffffff);
    if (_DAT_3ffbdc3c == 3) {
      uVar1 = rsr(in_PRID);
      _DAT_3ffbdc3c = uVar1 >> 0xd & 1;
    }
    memw();
    (*(code *)&SUB_40092bec)(0x3ffbdc34);
    uVar2 = FUN_400f39b8(param_1,_DAT_3ffbdc3c);
  }
  return uVar2;
}

