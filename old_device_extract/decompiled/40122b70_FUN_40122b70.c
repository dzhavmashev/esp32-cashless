// Function : FUN_40122b70
// Address  : 0x40122b70
// Size     : 89 bytes


void FUN_40122b70(int param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  DAT_3ffc7538 = 0xef;
  DAT_3ffc7539 = 0xbe;
  DAT_3ffc753a = 0xad;
  DAT_3ffc753b = 0xde;
  DAT_3ffc7540 = 0xff;
  DAT_3ffc7541 = 0xff;
  DAT_3ffc7542 = 0;
  DAT_3ffc7543 = 0;
  DAT_3ffc753d = 0;
  DAT_3ffc753e = 0;
  DAT_3ffc753f = 0;
  DAT_3ffc753c = 0xe8;
  memw();
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  cVar1 = *(char *)(param_1 + 0x20);
  *puVar2 = 0xdeadbeef;
  if (cVar1 != '\0') {
    puVar2[0x14] = puVar2[0x14] + 0x40;
  }
  memw();
  return;
}

