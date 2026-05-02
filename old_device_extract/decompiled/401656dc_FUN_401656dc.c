// Function : FUN_401656dc
// Address  : 0x401656dc
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401656dc(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((_DAT_3ffc0730 & 0x24) != 0) {
    iVar4 = *(int *)(*(int *)(param_1 + 4) + 4);
    puVar1 = (undefined4 *)(**(code **)(_DAT_3ffc1a34 + 0x16c))(8);
    iVar3 = (*(uint *)(iVar4 + 0x18) & 0xfff) + 0x1c;
    if (puVar1 != (undefined4 *)0x0) {
      iVar2 = (**(code **)(_DAT_3ffc1a34 + 0x16c))(iVar3);
      if (iVar2 != 0) {
        (*(code *)&SUB_4008b3d0)(iVar2,iVar4,iVar3);
        *puVar1 = 2;
        puVar1[1] = iVar2;
        memw();
        iVar3 = (*(code *)&SUB_40087bcc)(0xd,puVar1);
        if (iVar3 != 1) {
          return;
        }
        (**(code **)(_DAT_3ffc1a34 + 0xb0))(iVar2);
      }
      (**(code **)(_DAT_3ffc1a34 + 0xb0))(puVar1);
    }
  }
  return;
}

