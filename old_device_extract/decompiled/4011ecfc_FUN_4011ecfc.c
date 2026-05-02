// Function : FUN_4011ecfc
// Address  : 0x4011ecfc
// Size     : 190 bytes


int FUN_4011ecfc(undefined2 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  byte abStack_21 [33];
  
  uVar1 = FUN_40185644(0x3ffbf694);
  if ((uVar1 & 7) != 0) {
    uVar1 = (*(code *)&SUB_40094c54)("support/mac_addr.c",0x71,"orrect\n","st MAC\n");
  }
  iVar2 = FUN_401212c4(0x3ffbf694,param_1,uVar1);
  if (iVar2 == 0) {
    FUN_401212c4(0x3ffbf68c,abStack_21,8);
    uVar1 = (*(code *)&SUB_4005d144)(param_1,6);
    if (abStack_21[0] != uVar1) {
      if (((CONCAT21(*param_1,*(undefined1 *)((int)param_1 + 1)) & 0xffff) != 0x18fe) ||
         (0x31 < ((uint)*(byte *)(param_1 + 1) << 0x18 | (uint)*(byte *)((int)param_1 + 3) << 0x10 |
                  (uint)*(byte *)((int)param_1 + 5) | (uint)*(byte *)(param_1 + 2) << 8) +
                 0xcb957a39)) {
        uVar3 = (*(code *)&SUB_40094b80)();
        memw();
        FUN_4012113c(1,"_source","_addr.c",uVar3,"_source",abStack_21[0],uVar1);
        iVar2 = 0x109;
      }
    }
  }
  return iVar2;
}

