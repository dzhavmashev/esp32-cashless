// Function : FUN_4010b030
// Address  : 0x4010b030
// Size     : 40 bytes


void FUN_4010b030(uint param_1)

{
  if ((param_1 & 3) != 0) {
    (*(code *)&SUB_40094c54)("aligned",0x16d,"aligned","/memp.c");
  }
  FUN_4011b020();
  FUN_4011b040();
  FUN_4010afc4(param_1);
  return;
}

