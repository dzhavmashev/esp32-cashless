// Function : FUN_400f5164
// Address  : 0x400f5164
// Size     : 181 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400f5164(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (_DAT_3ffc5554 == (int *)0x0) {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_value",0x7f,"en");
    uVar1 = 0x103;
  }
  else if (param_1 < 8) {
    (*(code *)&SUB_40092a98)(0x3ffbdc50,0xffffffff);
    uVar2 = 1 << 0x20 - ((param_1 & 0xf) * -2 + 0x20);
    iVar3 = *_DAT_3ffc5554;
    memw();
    memw();
    *(uint *)(iVar3 + 0xb0) = uVar2 | *(uint *)(iVar3 + 0xb0);
    memw();
    memw();
    *(uint *)(iVar3 + 0xb0) = (uVar2 ^ 0xffffffff) & *(uint *)(iVar3 + 0xb0);
    memw();
    uVar1 = 0;
    (*(code *)&SUB_40092bec)(0x3ffbdc50);
  }
  else {
    uVar1 = (*(code *)&SUB_40094b80)();
    memw();
    FUN_4012113c(1,"llup_en","hz",uVar1,"llup_en","r_value",0x80,"r error");
    uVar1 = 0x102;
  }
  return uVar1;
}

