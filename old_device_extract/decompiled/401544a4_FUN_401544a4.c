// Function : FUN_401544a4
// Address  : 0x401544a4
// Size     : 88 bytes


bool FUN_401544a4(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 uVar4;
  
  cVar1 = *(char *)(param_1 + 0x32);
  if (cVar1 != '\x03') {
    if (cVar1 == '\x04') {
      return (bool)6;
    }
    return cVar1 != '\x01';
  }
  if (*(char *)(param_1 + 0xac) == '\x01') {
    bVar3 = *(char *)(param_1 + 0xab) - 1;
LAB_401544d9:
    if (bVar3 < 9) {
      uVar2 = 4;
      uVar4 = 5;
      goto LAB_401544fa;
    }
  }
  else if (*(char *)(param_1 + 0xac) == '\x02') {
    bVar3 = *(char *)(param_1 + 0xab) - 5;
    goto LAB_401544d9;
  }
  uVar2 = 2;
  uVar4 = 3;
LAB_401544fa:
  if ((*(uint *)(param_1 + 0xc) & 0x8000) != 0) {
    uVar2 = uVar4;
  }
  return (bool)uVar2;
}

