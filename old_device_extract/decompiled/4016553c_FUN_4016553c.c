// Function : FUN_4016553c
// Address  : 0x4016553c
// Size     : 135 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4016553c(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_40 [64];
  
  if (_DAT_3ffc1bb8 == (char *)0x0) {
    return 0;
  }
  *_DAT_3ffc1bb8 = '\x01' - *_DAT_3ffc1bb8;
  memw();
  memw();
LAB_401655b5:
  do {
    iVar3 = FUN_401654cc(auStack_40);
    if (iVar3 == -1) {
      return 0;
    }
    puVar1 = (undefined4 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(8);
  } while (puVar1 == (undefined4 *)0x0);
  iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(0x1c);
  if (iVar3 != 0) goto LAB_40165580;
  goto LAB_401655aa;
LAB_40165580:
  (*(code *)&SUB_4008b3d0)(iVar3,auStack_40,0x1c);
  *puVar1 = 3;
  puVar1[1] = iVar3;
  memw();
  iVar2 = (*(code *)&SUB_40087bcc)(0xd,puVar1);
  if (iVar2 == 1) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar3);
LAB_401655aa:
    (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar1);
  }
  goto LAB_401655b5;
}

