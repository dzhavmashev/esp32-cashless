// Function : FUN_401883dc
// Address  : 0x401883dc
// Size     : 147 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401883dc(int param_1)

{
  byte bVar1;
  code *pcVar2;
  undefined4 uVar3;
  undefined4 local_30 [12];
  
  local_30[0] = 0;
  bVar1 = **(byte **)(*(int *)(param_1 + 4) + 4);
  if (((bVar1 & 0xc) == 0) && ((bVar1 & 0xf0) == 0x80)) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0x1a8))(4,local_30);
    uVar3 = 4;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x19c);
  }
  else {
    if ((bVar1 & 0xc) == 0) {
      if (((bVar1 & 0xf0) + 0x60 & 0xd0) != 0) {
        return;
      }
      (**(code **)(_DAT_3ffc1a34 + 0x1a8))(7,local_30);
      (**(code **)(_DAT_3ffc1a34 + 0x19c))(7,bVar1 & 0xc,local_30[0]);
      return;
    }
    if ((bVar1 & 0xc) != 8) {
      return;
    }
    if ((bVar1 & 0x70) != 0x40) {
      return;
    }
    (**(code **)(_DAT_3ffc1a34 + 0x1a8))(9,local_30);
    uVar3 = 9;
    pcVar2 = *(code **)(_DAT_3ffc1a34 + 0x19c);
  }
  (*pcVar2)(uVar3,0,local_30[0]);
  return;
}

