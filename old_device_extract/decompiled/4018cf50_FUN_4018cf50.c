// Function : FUN_4018cf50
// Address  : 0x4018cf50
// Size     : 40 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4018cf50(void)

{
  undefined4 uVar1;
  undefined1 auStack_34 [52];
  
  uVar1 = 0x103;
  if (_DAT_3ffc5868 == 0) {
    (*(code *)&SUB_4008b3d0)(auStack_34,"sys_evt",0x14);
    uVar1 = FUN_4018d24c(auStack_34,&DAT_3ffc5868);
  }
  return uVar1;
}

