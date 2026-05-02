// Function : FUN_40151248
// Address  : 0x40151248
// Size     : 56 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40151248(void)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_60 [96];
  
  (*(code *)&SUB_4008b530)(auStack_60,0xff,0x40);
  iVar1 = _DAT_3ffbfc54 + 0x392;
  iVar2 = (*(code *)&SUB_4008b33c)(iVar1,auStack_60,0x40);
  if (iVar2 == 0) {
    (*(code *)&SUB_4008b530)(iVar1,0,0x40);
  }
  return 0;
}

