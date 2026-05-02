// Function : FUN_40154d88
// Address  : 0x40154d88
// Size     : 57 bytes


undefined4 FUN_40154d88(undefined1 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_40154dd4();
  iVar1 = FUN_40154d58();
  if (iVar1 != 0) {
    if (*(byte *)(iVar1 + 3) < 7) {
                    /* WARNING: Jumptable at 0x40154da8 did not pass sanity check. */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(&DAT_3f423ff8 + (uint)*(byte *)(iVar1 + 3) * 4))
                        (*(code **)(&DAT_3f423ff8 + (uint)*(byte *)(iVar1 + 3) * 4),param_1);
      return uVar2;
    }
    FUN_40147fe4(1,4,2,0x3f436b5c);
  }
  return 1;
}

