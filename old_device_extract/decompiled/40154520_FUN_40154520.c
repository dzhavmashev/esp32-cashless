// Function : FUN_40154520
// Address  : 0x40154520
// Size     : 89 bytes


void FUN_40154520(int param_1,undefined4 param_2)

{
  byte bVar1;
  char *pcVar2;
  
  bVar1 = *(byte *)(param_1 + 0x32);
  if (bVar1 == 2) {
    pcVar2 = "\x02\x01\x01";
    if (*(char *)(param_1 + 0x28a) == '\0') {
      pcVar2 = "\x01";
    }
  }
  else if (bVar1 < 3) {
    if (bVar1 != 1) {
      return;
    }
    pcVar2 = "\x18";
    if (*(char *)(param_1 + 0x28a) == '\0') {
      pcVar2 = "valid pcb";
    }
  }
  else if (bVar1 == 3) {
    pcVar2 = "rb";
    if (*(char *)(param_1 + 0x28a) == '\0') {
      pcVar2 = "";
    }
  }
  else {
    pcVar2 = "g";
    if (bVar1 != 4) {
      return;
    }
  }
  (*(code *)&SUB_4008bf10)(param_2,pcVar2);
  return;
}

