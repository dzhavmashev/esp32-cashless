// Function : FUN_40151280
// Address  : 0x40151280
// Size     : 65 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40151280(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_60 [96];
  
  (*(code *)&SUB_4008b530)(auStack_60,0xff,0x40);
  iVar1 = _DAT_3ffbfc54;
  iVar3 = _DAT_3ffbfc54 + 0x2f;
  iVar2 = (*(code *)&SUB_4008b33c)(iVar3,auStack_60,0x40);
  if (iVar2 == 0) {
    (*(code *)&SUB_4008b530)(iVar3,0,0x40);
    *(undefined1 *)(iVar1 + 0x6f) = 0;
    memw();
  }
  memw();
  return 0;
}

